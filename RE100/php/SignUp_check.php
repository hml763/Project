<?php
session_start();

$id=$_POST['id'];
$pw1=$_POST['password'];
$pw2=$_POST['password2'];
$name=$_POST['i_name'];

if($pw1!=$pw2){
  echo"비밀번호와 비밀번호 확인이 다릅니다.";
  echo"<a href=signUp.php>back page</a>";
  exit();
}

if($id==NULL||$pw1==NULL||$name==NULL){
  echo"빈칸을 모두 채우세요.";
  echo"<a href=signUp.php>back page</a>";
  exit();
}

$mysqli=mysqli_connect("localhost","root","159753","h_sole");
if(!$mysqli){
    die('could not connect:'.mysqli_error($mysqli));
}
$check= "select * from user_info where id='$id'";
$result=$mysqli->query($check);
if($result->num_rows==1){
  echo"중복된 id입니다.";
  echo"<a href=SignUp.php> back page</a>";
  exit();
}

$signup=mysqli_query($mysqli,"Insert into user_info values('$id','$pw1','$name')");
if($signup){
  header('Location: ./login.php');
}
?>
