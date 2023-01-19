<?php

    $dbname = "bbtrhiyulkgpqgdcf9lc";
    $host = "bbtrhiyulkgpqgdcf9lc-mysql.services.clever-cloud.com";
    $user = "u2p8wvu70jujlkoh";
    $password = "neMQfXEBCgbAG8qSrIWF";

    $respuesta_estado = "";
    $e = "";

    try{
        $dsn = "mysql:host=$host;dbname=$dbname";
        $dbh = new PDO($dsn, $user, $password);
        $respuesta_estado = $respuesta_estado . "\nConexion Exitosa";
    } catch (PDOException $e){
        $respuesta_estado = $respuesta_estado . "\n" . $e->getMessage();
    }

    $sql = "SELECT Area FROM Areas ";

    $stmt = $dbh->prepare($sql);
    $stmt->setFetchMode(PDO::FETCH_ASSOC);
    $stmt->execute();

    $areas = [];
    while($fila = $stmt->fetch()){
        array_push($areas, $fila["Area"]);
    }

    $dbh = null;
    echo json_encode($areas);

?>