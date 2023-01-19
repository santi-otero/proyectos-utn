<?php
    session_start();
    if(!isset($_SESSION["user"])) header("Location: ./FormularioLogin.html");
    else header("Location: ./app_modulo1/index.php");
?>