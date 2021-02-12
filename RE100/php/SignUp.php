<!doctype html>
<html>
<head>
  <meta charset="utf-8">
  <title></title>

  <link href ="./style/signup.css" rel="stylesheet">
  <style>
  li{
    font-family: "sans-serif";
     list-style:none;
     padding-left:0px;
     }
  </style>
  </head>
  <body>
    <form method="post" action="SignUp_check.php">
    <div class="main-frame">
    <a href="SignUp.php" > <img src="./img/logo.gif" id='logo'></a>
    <div class="input">
      <ul>
        <li><label><input type="text" name=id placeholder="UserID" id="txt1"></label></li>
        <li><label><input type ="password" name=password placeholder="PASSWORD" id="txt1"></label></li>
        <li><label> <input type ="password" name=password2 placeholder="PASSWORD" id="txt1"></label></li>
        <li><label><input type="text" name=i_name placeholder="Your Name" id="txt1"></label></li>
        <input type="image" src="./img/회원가입.png" id=log-img >
    </ul>
    </div>
  </div>
      </form>
  </body>

</html>
