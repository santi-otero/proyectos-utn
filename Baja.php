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

    $sql = "DELETE FROM Empleados WHERE ID=:ID";

    $stmt = $dbh->prepare($sql);
    $stmt->bindParam(":ID", $id);
    $stmt->execute();
    $respuesta_estado = $respuesta_estado . "<br/>Baja del registro con id : " . $id . " realizada";
    $dbh = null;
    echo json_encode($respuesta_estado);

?>