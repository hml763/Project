#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "EMGFilters.h"

#define TIMING_DEBUG 1

#define SensorInputPin A0 // input pin number

EMGFilters myFilter;
// discrete filters must works with fixed sample frequence
// our emg filter only support "SAMPLE_FREQ_500HZ" or "SAMPLE_FREQ_1000HZ"
// other sampleRate inputs will bypass all the EMG_FILTER
int sampleRate = SAMPLE_FREQ_1000HZ;
// For countries where power transmission is at 50 Hz
// For countries where power transmission is at 60 Hz, need to change to
// "NOTCH_FREQ_60HZ"
// our emg filter only support 50Hz and 60Hz input
// other inputs will bypass all the EMG_FILTER
int humFreq = NOTCH_FREQ_50HZ;

// Calibration:
// put on the sensors, and release your muscles;
// wait a few seconds, and select the max value as the threshold;
// any value under threshold will be set to zero
static int Threshold = 7000;

unsigned long timeStamp;
unsigned long timeBudget;

void setup() {
    /* add setup code here */
    myFilter.init(sampleRate, humFreq, true, true, true);

    // open serial
    Serial.begin(9600);

    // setup for time cost measure
    // using micros()
    timeBudget = 1e6 / sampleRate;
    // micros will overflow and auto return to zero every 70 minutes
}

void loop() {
    /* add main program code here */
    // In order to make sure the ADC sample frequence on arduino,
    // the time cost should be measured each loop
    /*------------start here-------------------*/
    timeStamp = micros();

    int Value = analogRead(SensorInputPin);

    // filter processing
    int DataAfterFilter = myFilter.update(Value);

    int envlope = sq(DataAfterFilter)*10;
    // any value under threshold will be set to zero
    envlope = (envlope > Threshold) ? envlope : 0;

    timeStamp = micros() - timeStamp;
    if (TIMING_DEBUG) {
        Serial.print(-10000); // To freeze the lower limit
        Serial.print(" ");
        Serial.print(200000); // To freeze the upper limit
        Serial.print(" ");
//Serial.println(DataAfterFilter); // To send all three  
        Serial.println(envlope);


//         Serial.print("Read Data: "); Serial.println(Value);
//         Serial.print("Filtered Data: ");Serial.println(DataAfterFilter);
//        Serial.print("Squared Data: ");
//        Serial.println(envlope);
//         Serial.print("Filters cost time: "); Serial.println(timeStamp);
        // the filter cost average around 520 us
    }


    /*------------end here---------------------*/
    // if less than timeBudget, then you still have (timeBudget - timeStamp) to
    // do your work
    delayMicroseconds(5000);
    // if more than timeBudget, the sample rate need to reduce to
    // SAMPLE_FREQ_500HZ
}
  
