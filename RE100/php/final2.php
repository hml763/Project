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
    
$result1 = mysqli_query($conn, "SELECT * FROM demo");
$result2 = mysqli_query($conn, "SELECT * FROM demo_click");
$result3 = mysqli_query($conn, "SELECT * FROM demo_viewer");

$str_mdh1="";
$str_value1="";
$str_result1="";

while ($row = mysqli_fetch_array($result1)) {
    $str_mdh1 .="'".$row['created_at']."',";
    while(1) {
        $str_value1 = $str_value1 + $row['numberofview'];
        
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
        $str_value3 = $str_value3 + $row['numberofview'];
        
        break;
    }
    $str_result3 .="".$str_value3.",";
}
 
// 오른쪽 공백 제거
$str_mdh3= substr($str_mdh3,0,-1);
$str_result3= substr($str_result3,0,-1);
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
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
            text: '각 시스템 보유 전력량'
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
            },
                {
                    name: 'data2',
                    data: [<?php echo $str_result2?>] 
                },
                {
                    name: 'data3',
                    data: [<?php echo $str_result3?>]
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
    
<?php
	if(isset($_POST['Submit'])){//if the submit button is clicked
	
    $id = $_POST['id'];
	
	$time = $_POST['created_at'];
	
	$value = $_POST['numberofview'];
		
	$update = "INSERT INTO demo ('id', 'numberofview', 'created_at') VALUES ('$id', '$value', '$time')";
	$conn->query($update) or die("Cannot insert");//update or error
	}
?>
    
<?php
//Create a query
$sql = "SELECT * FROM demo";
//submit the query and capture the result
$result = $conn->query($sql) or die(mysql_error());
$query=getenv(QUERY_STRING);
parse_str($query);
//$ud_title = $_POST['Title'];
//$ud_pub = $_POST['Publisher'];
//$ud_pubdate = $_POST['PublishDate'];
//$ud_img = $_POST['Image'];
?>
    
<form action="" method="post">
<?php
	
$row = $result->fetch_assoc();	{?>
    
<table border="0" cellspacing="10">
    <tr>
        <td>id:</td> <td><input type="text" name="id" value=""></td>
    </tr>
    <tr>
        <td>numberofview:</td> <td><input type="text" name="numberofview" value=""></td>
    </tr>
    <tr>
        <td>created_at:</td> <td><input type="text" name="created_at" value="NOW()"></td>
    </tr>
    <tr>
        <td><INPUT TYPE="Submit" VALUE="Update the Record" NAME="Submit"></td>
    </tr>
</table>
<?php	}
	?>
</form>
</body>
</html>