<?php
 
/*// PHP 에러 코드 확인
ini_set('display_errors', 'On');
error_reporting(E_ALL|E_STRICT);
 */
// MySQL 접속
/*$mysql_host = 'localhost';
$mysql_user = 'root';
$mysql_password = '159753';
$mysql_db = 'h_sole';
$conn = mysqli_connect($mysql_host, $mysql_user, $mysql_password);
if(!$conn){
            die('could not connect:'.mysqli_error($conn));
        }

$dbconn = mysqli_select_db($mysql_db, $conn);
 
// DB에서 원하는 데이터 검색
$sql=" 
select * from (
SELECT DATE_FORMAT( created_at,  '%m-%d %HH' )  mdh , numberofview  atemper
FROM  `demo_viewer` 
GROUP BY DATE_FORMAT( created_at,  '%Y%m%d%H' ) 
order by created_at desc
) t_a
order by t_a.mdh 
";
 
$result = mysqli_query($sql) ;*/
$conn =mysqli_connect("localhost", "root", "159753", "h_sole");
if(!$conn){
    die('could not connect:'.mysqli_error($conn));
}
    
$result1 = mysqli_query($conn, "SELECT * FROM data1");
$result2 = mysqli_query($conn, "SELECT * FROM demo_click");
$result3 = mysqli_query($conn, "SELECT * FROM data3");

$str_mdh1="";
$str_value1="";
$str_result1="";

while ($row = mysqli_fetch_array($result1)) {
    $str_mdh1 .="'".$row['created_at']."',";
    while(1) {
        $str_value1 = $str_value1 + $row['numberofviewer'];
        
        break;
    }
    $str_result1 .="".$str_value1.",";
}

$str_mdh1= substr($str_mdh1,0,-1);
$str_result1= substr($str_result1,0,-1);

$str_mdh2="";
$str_value2="";
$str_result2="";
 
// 문자열 연결
while ($row = mysqli_fetch_array($result2)) {
    $str_mdh2 .="'".$row['created_at']."',";
    while(1) {
        $str_value2 = $str_value2 + $row['numberofclick'];
        
        break;
    }
    $str_result2 .="".$str_value2.",";
}

$str_mdh2= substr($str_mdh2,0,-1);
$str_result2= substr($str_result2,0,-1);

$str_mdh3="";
$str_value3="";
$str_result3="";

while ($row = mysqli_fetch_array($result3)) {
    $str_mdh3 .="'".$row['created_at']."',";
    while(1) {
        $str_value3 = $str_value3 + $row['numberofviewer'];
        
        break;
    }
    $str_result3 .="".$str_value3.",";
}
 
// 오른쪽 공백 제거
$str_mdh3= substr($str_mdh3,0,-1);
$str_result3= substr($str_result3,0,-1);
?>

<!DOCTYPE HTML>
<html>
<head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
        <title>House Monitor</title>
        <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
        <!--<style type="text/css">${demo.css}</style>-->
        <script type="text/javascript">
 
$(function () {
    $('#temp1').highcharts({
        colors: ['#BFDEAC'],
        chart: {
            type: 'area'
        },
        title: {
            text: 'Price'
        },
        subtitle: {
            text: ''
        },
        xAxis: {
            categories: [<?php echo $str_mdh1?>]
        },
        yAxis: {
            title: {
                text: 'Power'
            }
        },
        plotOptions: {
            line: {
                dataLabels: {
                    enabled: true
                },
                enableMouseTracking: false
            }
        },
        series: [{
            name: 'data1',
            data: [<?php echo $str_result1?>]
            }]
      });
    $('#temp2').highcharts({
        chart: {
            type: 'line'
        },
        title: {
            text: 'SMP'
        },
        subtitle: {
            text: ''
        },
        xAxis: {
            categories: [<?php echo $str_mdh1?>]
        },
        yAxis: {
            title: {
                text: 'Power'
            }
        },
        plotOptions: {
            line: {
                dataLabels: {
                    enabled: true
                },
                enableMouseTracking: false
            }
        },
        series: [{
            name: 'data2',
            data: [<?php echo $str_result1?>]
            }]
      });
    $('#temp3').highcharts({
        colors: ['#980000'],
        chart: {
            type: 'area'
        },
        title: {
            text: 'EMP'
        },
        subtitle: {
            text: ''
        },
        xAxis: {
            categories: [<?php echo $str_mdh2?>]
        },
        yAxis: {
            title: {
                text: 'Power'
            }
        },
        plotOptions: {
            line: {
                dataLabels: {
                    enabled: true
                },
                enableMouseTracking: false
            }
        },
        series: [{
            name: 'data3',
            data: [<?php echo $str_result3?>]
            }]
      });
});
        </script>
</head>
<body>
        <script src="https://code.highcharts.com/highcharts.js"></script>
        <script src="https://code.highcharts.com/modules/exporting.js"></script>
        <div id="temp1" style="width: 750px; height: 500px; margin: 30px auto"></div>
        <div id="temp2" style="width: 750px; height: 500px; margin: 30px auto"></div>
        <div id="temp3" style="width: 750px; height: 500px; margin: 30px auto"></div>
</body>
</html>