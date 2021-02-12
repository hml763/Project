<!DOCTYPE html>
<html>
    <head>

        <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.1.6/Chart.min.js"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.1.6/Chart.bundle.min.js"></script>
        <script src="https://code.jquery.com/jquery-2.2.4.min.js"></script>
      
        <title></title>

        <link href ="./style/RE100_table.css" rel="stylesheet">
    
    </head>

    <body>
        <div class="main-frame">
            <a href="RE100.php" > <img src="./img/logo.gif" id=logo></a>
            <div class="menu">
                <a href="RE100.php" >    <img src="./img/KPX.png" class="menu-img"> </a>
                <a href="seller.php" >    <img src="./img/판매 사업자.png" class="menu-img"> </a>
                <a href="buyer.php" >    <img src="./img/구매 사업자.png" class="menu-img"> </a>
                <a href="market.php" >  <img src="./img/전력시장.png" class="menu-img"> </a>
            </div>
            <div class="contents">
                <?php include("final.php"); ?>
            </div>
            
  
            <div class = "button">
            </div>
        </div>          
    </body>
</html>