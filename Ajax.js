$(document).ready(function(){
    $('#BotonDisparador').attr("class","inactivo");
});

document.getElementById("contenedorBoton").onmouseover=function(){
    document.getElementById("BotonDisparador").className="activo";
}
document.getElementById("contenedorBoton").onmouseout=function(){
    document.getElementById("BotonDisparador").className="inactivo";
}

$("#BotonDisparador").click(function(){
        $("#contenedorRespuesta").empty();
        $("#contenedorRespuesta").html("<h2>Esperando respuesta...</h2>");
        $("#contenedorEstado").empty();
        $("#contenedorEstado").html("<h2>Estado de requerimiento: </h2>");

        $.ajax({
            type:"post",
            url: "./response.php",
            data: {clave: $("#clave").val()},

            success:function(respuestaDelServer){
                $("#contenedorRespuesta").empty();
                $("#contenedorRespuesta").html("<h1>Respuesta:</h1><h2>"+respuestaDelServer+"</h2>");
                $("#contenedorEstado").append("<h3 style='color:white;'>success</h3>");
            }
        });
});