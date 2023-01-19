<?php
    session_start();
    if(isset($_SESSION["user"])) header("Location: ./index.php");
    else{
        
        $dbname = "bbtrhiyulkgpqgdcf9lc";
        $host = "bbtrhiyulkgpqgdcf9lc-mysql.services.clever-cloud.com";
        $user = "u2p8wvu70jujlkoh";
        $password = "neMQfXEBCgbAG8qSrIWF";

        $username = $_POST["user"];
        $contra = hash("sha256", $_POST["password"]);
        $respuesta_estado = "";
        $e = "";

        try{
            $dsn = "mysql:host=$host;dbname=$dbname";
            $dbh = new PDO($dsn, $user, $password);
            $respuesta_estado = $respuesta_estado . "Conexion Exitosa";
        } catch (PDOException $e){
            $respuesta_estado = $respuesta_estado . "\n" . $e->getMessage();
        }

        $sql = "SELECT Contra FROM Usuario WHERE Usuario=:Usuario";
        $stmt = $dbh->prepare($sql);
        $stmt->bindParam(":Usuario", $username);
        $stmt->setFetchMode(PDO::FETCH_ASSOC);
        $stmt->execute();

        
        while($fila = $stmt->fetch()){
            $objUser = new stdclass();
            $objUser->Password = $fila["Contra"];
            $objUser->ID = session_id();
        }
        $dbh = null;

        if(isset($objUser->Password)){
            if($contra == $objUser->Password){
                $_SESSION["user"] = $username;
                $_SESSION["session_id"] = $objUser->ID;
                echo "<body style='background-color: tomato;''>";
                echo    "<div style='width:40%;height:300px;padding:5px;border:2px solid black;margin: auto;margin-top:10%;text-align: center;'>";
                echo        "<h2> Conexion exitosa, bienvenido! </h2><h3>Nombre de usuario: " . $_SESSION["user"] . "<br/>ID: " . $_SESSION["session_id"] . "</h3>";
                echo <<< ASD
                            <hr/>
                            <button onclick="location.href='./app_modulo1/index.php'">Ingresar a la aplicacion</button>
                            <button onclick="location.href='./destruirSesion.php'">Terminar sesion</button>
                        </div>
                    </body>"
                    ASD;
            }
            else{
                echo <<< ASD
                    <body style="background-color: tomato;">
                        <div style="width:40%;height:300px;padding:5px;border:2px solid black;margin: auto;margin-top:10%;text-align: center;">
                            <h2> Error!! Contraseña incorrecta. </h2><hr/>
                            <button onclick="location.href='./index.php'">Volver</button>
                        </div>
                    </body>
                ASD;
            }
        }
        else{
            echo <<< ASD
                    <body style="background-color: tomato;">
                        <div style="width:40%;height:300px;padding:5px;border:2px solid black;margin: auto;margin-top:10%;text-align: center;">
                            <h2> Error!! Usuario no encontrado. </h2><hr/>
                            <button onclick="location.href='./index.php'">Volver</button>
                        </div>
                    </body>
                ASD;
        }
    }
?>