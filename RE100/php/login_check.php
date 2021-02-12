<?php
session_start();

$mysqli=mysqli_connect("localhost","root","159753","h_sole");
$temp1=$_POST['id'];
$temp2=$_POST['password'];

$check="select * from user_info where id='$temp1'";
$result=$mysqli->query($check);


echo $temp1;
echo $temp2;

if($result->num_rows==1){

  $row=$result->fetch_array(MYSQLI_ASSOC);
  if($row['password']==$temp2){
    $_SESSION['id']=$temp1;

    if(isset($_SESSION['id'])){
      header('Location: ./RE100.php');
    }
    else{
      echo "세션 저장 실패";
    }
  }
  else{
    echo "1wring id or pw";
  }
}
else{
  echo "2wrong id or pw";
}
?>
