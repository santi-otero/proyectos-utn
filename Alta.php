<?php
    
    $dbname = "bbtrhiyulkgpqgdcf9lc";
    $host = "bbtrhiyulkgpqgdcf9lc-mysql.services.clever-cloud.com";
    $user = "u2p8wvu70jujlkoh";
    $password = "neMQfXEBCgbAG8qSrIWF";

    $id = $_POST["id"];
    $nombre = $_POST["nombre"];
    $area = $_POST["area"];
    $sueldo = $_POST["sueldo"];
    $fecha = $_POST["fecha"];
    
    $respuesta_estado = "";
    $e = "";

    try{
        $dsn = "mysql:host=$host;dbname=$dbname";
        $dbh = new PDO($dsn, $user, $password);
        $respuesta_estado = $respuesta_estado . "Conexion Exitosa!";
    } catch (PDOException $e){
        $respuesta_estado = $respuesta_estado . "\n" . $e->getMessage();
    }
    
    if(empty($_FILES["pdf"]["name"])) {
        $sql = "INSERT INTO Empleados (ID, Nombre, Area, Sueldo, Fecha, PDF) 
            VALUES (:ID, :Nombre, :Area, :Sueldo, :Fecha, '');";
        $stmt = $dbh->prepare($sql);
        $stmt->bindParam(":ID", $id);
        $stmt->bindParam(":Nombre", $nombre);
        $stmt->bindParam(":Area", $area);
        $stmt->bindParam(":Sueldo", $sueldo);
        $stmt->bindParam(":Fecha", $fecha);
        $respuesta_estado = $respuesta_estado . "<br/><br/>" . $nombre . " ingresado a la base de datos, 
                                        al area de " . $area . ", el dia " . $fecha . ", sin PDF adjunto.";
    }
    else{
        $pdf = base64_encode(file_get_contents($_FILES["pdf"]["tmp_name"]));
        $sql = "INSERT INTO Empleados (ID, Nombre, Area, Sueldo, Fecha, PDF) 
            VALUES (:ID, :Nombre, :Area, :Sueldo, :Fecha, :PDF);";
        $stmt = $dbh->prepare($sql);
        $stmt->bindParam(":ID", $id);
        $stmt->bindParam(":Nombre", $nombre);
        $stmt->bindParam(":Area", $area);
        $stmt->bindParam(":Sueldo", $sueldo);
        $stmt->bindParam(":Fecha", $fecha);
        $stmt->bindParam(":PDF", $pdf);
        $respuesta_estado = $respuesta_estado . "<br/><br/>" . $nombre . " ingresado a la base de datos, 
                                        al area de " . $area . ", el dia " . $fecha . ", con PDF adjunto.";
    }
    
    try{
        $stmt->execute();
    } catch (PDOException $e){
        if (strstr( $e->getMessage(), 'Duplicate entry' )) $respuesta_estado = "Entrada duplicada<br/>Por favor ingrese otro código";
    }
    

    $dbh = null;
    echo json_encode($respuesta_estado);

?>