<?php
    sleep(3);
    if(isset($_POST["ID"]) && isset($_POST["login"]) && isset($_POST["nom"]) && isset($_POST["ape"]) && isset($_POST["fecha"])){
        $objUsuario = new stdclass;
        $objUsuario->ID = $_POST["ID"];
        $objUsuario->login = $_POST["login"]; 
        $objUsuario->nom = $_POST["nom"];
        $objUsuario->ape = $_POST["ape"];
        $objUsuario->fecha = $_POST["fecha"];
        $JsonUsuario = json_encode($objUsuario);
        echo $JsonUsuario;
    }
?>