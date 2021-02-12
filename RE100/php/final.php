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
    
    $result = mysqli_query($conn, "SELECT * FROM demo");
    /*$row = mysqli_fetch_assoc($result);*/

$str_mdh="";
$str_value="";
$str_result="";
 
// 문자열 연결
while ($row = mysqli_fetch_array($result)) {
    $str_mdh .="'".$row['created_at']."',";
    while(1) {
        $str_value = $str_value + $row['numberofview'];
        
        break;
    }
    $str_result .="".$str_value.",";
}
 
// 오른쪽 공백 제거
$str_mdh= substr($str_mdh,0,-1);
$str_result= substr($str_result,0,-1);
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
    $('#temp').highcharts({
        chart: {
            type: 'line'
        },
        title: {
            text: '보유 시스템 충전량'
        },
        subtitle: {
            text: ''
        },
        xAxis: {
            categories: [<?php echo $str_mdh?>]
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
            name: 'data',
            data: [<?php echo $str_result?>]
        }]
      });
    /*$('#humi').highcharts({
        chart: {
            type: 'line'
   },
        title: {
            text: 'Humidity'
        },
        xAxis: {
            categories: [<?php echo $str_mdh?>]
        },
        yAxis: {
            title: {
                text: 'humidity (%)'
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
            name: 'HOUSE',
            data: [<?php echo $str_ahumier?>]
        }]
    });*/
});
        </script>
</head>
<body>
        <script src="https://code.highcharts.com/highcharts.js"></script>
        <script src="https://code.highcharts.com/modules/exporting.js"></script>
        <div id="temp" style="width: 800px; height: 500px; margin: 30px auto"></div>
</body>
</html>


