<?php

    $dbname = "bbtrhiyulkgpqgdcf9lc";
    $host = "bbtrhiyulkgpqgdcf9lc-mysql.services.clever-cloud.com";
    $user = "u2p8wvu70jujlkoh";
    $password = "neMQfXEBCgbAG8qSrIWF";

    $id = $_GET["ID"];
    $respuesta_estado = "";
    $e = "";

    try{
        $dsn = "mysql:host=$host;dbname=$dbname";
        $dbh = new PDO($dsn, $user, $password);
        $respuesta_estado = $respuesta_estado . "\nConexion Exitosa!";
    } catch (PDOException $e){
        $respuesta_estado = $respuesta_estado . "\n" . $e->getMessage();
    }

    $sql = "SELECT PDF FROM Empleados WHERE ID = :ID";

    $stmt = $dbh->prepare($sql);
    $stmt->bindParam(":ID", $id);
    $stmt->setFetchMode(PDO::FETCH_ASSOC);
    $stmt->execute();

    while($fila = $stmt->fetch()){
        $objEmpleado = new stdclass();
        $objEmpleado->PDF = ($fila["PDF"]);
        if(!empty($objEmpleado->PDF)) $respuesta_estado = $respuesta_estado . "<br/>PDF encontrado";
        else $respuesta_estado = $respuesta_estado . "<br/>PDF no encontrado";
    }
    $objEmpleado->respuesta_estado = $respuesta_estado;
    $dbh = null;
    echo json_encode($objEmpleado,JSON_INVALID_UTF8_SUBSTITUTE);
?>