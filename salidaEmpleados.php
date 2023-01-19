<?php
    
    sleep(2);

    $dbname = "bbtrhiyulkgpqgdcf9lc";
    $host = "bbtrhiyulkgpqgdcf9lc-mysql.services.clever-cloud.com";
    $user = "u2p8wvu70jujlkoh";
    $password = "neMQfXEBCgbAG8qSrIWF";

    $f_ID = $_POST["f_ID"];
    $f_Nombre = $_POST["f_Nombre"];
    $f_Area = $_POST["f_Area"];
    $f_Sueldo = $_POST["f_Sueldo"];
    $f_Fecha = $_POST["f_Fecha"];
    $orden = $_POST["orden"];

    $respuesta_estado = "";
    $e = "";

    try{
        $dsn = "mysql:host=$host;dbname=$dbname";
        $dbh = new PDO($dsn, $user, $password);
        $respuesta_estado = $respuesta_estado . "\nConexion Exitosa";
    } catch (PDOException $e){
        $respuesta_estado = $respuesta_estado . "\n" . $e->getMessage();
    }

    $sql = "select * from Empleados where ";
    $sql = $sql . "ID LIKE CONCAT('%',:ID,'%') and ";
    $sql = $sql . "Nombre LIKE CONCAT('%',:Nombre,'%') and ";
    $sql = $sql . "Area LIKE CONCAT('%',:Area,'%') and ";
    $sql = $sql . "Sueldo LIKE CONCAT('%',:Sueldo,'%') and ";
    $sql = $sql . "Fecha LIKE CONCAT('%',:Fecha,'%')";
    $sql = $sql . " ORDER BY $orden";

    $stmt = $dbh->prepare($sql);

    $stmt->bindParam(":ID", $f_ID);
    $stmt->bindParam(":Nombre", $f_Nombre);
    $stmt->bindParam(":Area", $f_Area);
    $stmt->bindParam(":Sueldo", $f_Sueldo);
    $stmt->bindParam(":Fecha", $f_Fecha);

    $stmt->setFetchMode(PDO::FETCH_ASSOC);
    $stmt->execute();

    $empleados=[];
    $objEmpleado;
    while($fila = $stmt->fetch()){
        $objEmpleado = new stdclass();
        $objEmpleado->ID = $fila["ID"];
        $objEmpleado->Nombre = $fila["Nombre"];
        $objEmpleado->Area = $fila["Area"];
        $objEmpleado->Sueldo = $fila["Sueldo"];
        $objEmpleado->Fecha = $fila["Fecha"];

        array_push($empleados,$objEmpleado);
    }

    $objEmpleados = new stdclass();
    $objEmpleados->empleados = $empleados;
    $objEmpleados->cuenta = count($empleados);
    $salidaJson = json_encode($objEmpleados);

    $dbh = null;

    echo $salidaJson;
?>