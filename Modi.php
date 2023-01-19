<?php
    
    $dbname = "bbtrhiyulkgpqgdcf9lc";
    $host = "bbtrhiyulkgpqgdcf9lc-mysql.services.clever-cloud.com";
    $user = "u2p8wvu70jujlkoh";
    $password = "neMQfXEBCgbAG8qSrIWF";

    $id = $_POST["id_modi"];
    $nombre = $_POST["nombre_modi"];
    $area = $_POST["area_modi"];
    $sueldo = $_POST["sueldo_modi"];
    $fecha = $_POST["fecha_modi"];
    
    $respuesta_estado = "";
    $e = "";

    try{
        $dsn = "mysql:host=$host;dbname=$dbname";
        $dbh = new PDO($dsn, $user, $password);
        $respuesta_estado = $respuesta_estado . "\nConexion Exitosa!";
    } catch (PDOException $e){
        $respuesta_estado = $respuesta_estado . "\n" . $e->getMessage();
    }
    
    if(empty($_FILES["pdf_modi"]["name"])) {
        $sql = "UPDATE Empleados SET 
                ID=:ID, Nombre=:Nombre, Area=:Area, Sueldo=:Sueldo, Fecha=:Fecha, PDF=''
                WHERE  ID=:ID;";
        $stmt = $dbh->prepare($sql);
        $stmt->bindParam(":ID", $id);
        $stmt->bindParam(":Nombre", $nombre);
        $stmt->bindParam(":Area", $area);
        $stmt->bindParam(":Sueldo", $sueldo);
        $stmt->bindParam(":Fecha", $fecha);
        $respuesta_estado = $respuesta_estado . "<br/><br/>Modifiacion de registro con id : " . $id . " exitosa. <br/> No trae PDF adjunto.";
    }
    else{
        $pdf = base64_encode(file_get_contents($_FILES["pdf_modi"]["tmp_name"]));
        $sql = "UPDATE Empleados SET 
                ID=:ID, Nombre=:Nombre, Area=:Area, Sueldo=:Sueldo, Fecha=:Fecha, PDF=:PDF
                WHERE  ID=:ID;";
        $stmt = $dbh->prepare($sql);
        $stmt->bindParam(":ID", $id);
        $stmt->bindParam(":Nombre", $nombre);
        $stmt->bindParam(":Area", $area);
        $stmt->bindParam(":Sueldo", $sueldo);
        $stmt->bindParam(":Fecha", $fecha);
        $stmt->bindParam(":PDF", $pdf);
        $respuesta_estado = $respuesta_estado . "<br/><br/>Modifiacion de registro con id : " . $id . " exitosa. <br/> Trae PDF adjunto.";
    }
    
    $stmt->execute();

    $dbh = null;
    echo json_encode($respuesta_estado);

?>