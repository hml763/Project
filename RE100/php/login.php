<!doctype html>
<html>
<head>

<title>로그인</title>

<link rel="stylesheet" href="./style.css">
<style>
ul{
   list-style:none;
   padding-left:0px;
   }
</style>
</head>
<body>
  <form method="post" action="login_check.php">
    <div class="login-frame">
        <a href="login.php" > <img src="./img/logo.gif" id=logo></a>
      <div class="input">
    <ul>
      <li><label for="top">Log in to RE100 ElectricityMarket</label></li>
      <li> <input type ="text" placeholder="ID" name="id" id="txt1"></li>
      <li> <input type="password" placeholder="PASSWORD" name="password" id="txt1"></li>
<input type="image" src="./img/로그인.png" id=log-img >
        <li>  <a href ="signup.php"> <img src="./img/회원가입.png" id=log-img></a></li>
    </ul>
  </div>
  </div>
</form>

</body>

</html>
