$(document).ready(function(){
    $("#orden").val("Area");
    $("#FormAltas").css("visibility", "hidden");
    $("#FormAltas").css("pointer-events", "none");
    $("#FormModi").css("visibility", "hidden");
    $("#FormModi").css("pointer-events", "none");
    $("#VentanaPDF").css("visibility", "hidden");
    $("#VentanaPDF").css("pointer-events", "none");
    $("#VentanaRespuesta").css("visibility", "hidden");
    $("#VentanaRespuesta").css("pointer-events", "none");
    llenaAreas();
});
$("#th_Empleados_ID").click(function(){
    $("#orden").val("ID");
});
$("#th_Empleados_Nombre").click(function(){
    $("#orden").val("Nombre");
});
$("#th_Empleados_Area").click(function(){
    $("#orden").val("Area");
});
$("#th_Empleados_Sueldo").click(function(){
    $("#orden").val("Sueldo");
});
$("#th_Empleados_Fecha").click(function(){
    $("#orden").val("Fecha");
});
$("#alta").click(function(){
    $("#FormAltas").css("visibility", "visible");
    $("#FormAltas").css("pointer-events", "all");
    $("#ContenidoMedio").css("opacity", "0.3");
    $("#ContenidoMedio").css("pointer-events", "none");
    $("#ordenYbotones").css("opacity", "0.3");
    $("#ordenYbotones").css("pointer-events", "none");
    $("#totalRegistros").css("opacity", "0.3");
    $("#totalRegistros").css("pointer-events", "none");
    $("#cuerpoTabla").css("opacity", "0.3");
    $("#cuerpoTabla").css("pointer-events", "none");
});
$("#cerrar1").click(function(){
    $("#FormAltas").css("visibility", "hidden");
    $("#FormAltas").css("pointer-events", "none");
    $("#ContenidoMedio").css("opacity", "1");
    $("#ContenidoMedio").css("pointer-events", "all");
    $("#ordenYbotones").css("opacity", "1");
    $("#ordenYbotones").css("pointer-events", "all");
    $("#totalRegistros").css("opacity", "1");
    $("#totalRegistros").css("pointer-events", "all");
    $("#cuerpoTabla").css("opacity", "1");
    $("#cuerpoTabla").css("pointer-events", "all");
    document.getElementById("AltasForm").reset();
});
$("#cerrar2").click(function(){
    $("#FormModi").css("visibility", "hidden");
    $("#FormModi").css("pointer-events", "none");
    $("#ContenidoMedio").css("opacity", "1");
    $("#ContenidoMedio").css("pointer-events", "all");
    $("#ordenYbotones").css("opacity", "1");
    $("#ordenYbotones").css("pointer-events", "all");
    $("#totalRegistros").css("opacity", "1");
    $("#totalRegistros").css("pointer-events", "all");
    $("#cuerpoTabla").css("opacity", "1");
    $("#cuerpoTabla").css("pointer-events", "all");
    document.getElementById("ModiForm").reset();
});
$("#cerrar3").click(function(){
    $("#VentanaPDF").css("visibility", "hidden");
    $("#VentanaPDF").css("pointer-events", "none");
    $("#ContenidoMedio").css("opacity", "1");
    $("#ContenidoMedio").css("pointer-events", "all");
    $("#ordenYbotones").css("opacity", "1");
    $("#ordenYbotones").css("pointer-events", "all");
    $("#totalRegistros").css("opacity", "1");
    $("#totalRegistros").css("pointer-events", "all");
    $("#cuerpoTabla").css("opacity", "1");
    $("#cuerpoTabla").css("pointer-events", "all");
    $("#ContenidoPDF").empty();
});
$("#submit").click(function(){
        if($("#id").val() == "" || $("#nombre").val() == "" || $("#sueldo").val() == "" || $("#fecha").val() == ""){
            alert("Por favor complete todos los campos. (PDF opcional)");
        }
        else{
            DarDeAlta();
            $("#FormAltas").css("visibility", "hidden");
            $("#FormAltas").css("pointer-events", "none");
            $("#ContenidoMedio").css("opacity", "1");
            $("#ContenidoMedio").css("pointer-events", "all");
            $("#ordenYbotones").css("opacity", "1");
            $("#ordenYbotones").css("pointer-events", "all");
            $("#totalRegistros").css("opacity", "1");
            $("#totalRegistros").css("pointer-events", "all");
            $("#cuerpoTabla").css("opacity", "1");
            $("#cuerpoTabla").css("pointer-events", "all");
            document.getElementById("AltasForm").reset();
        }
});
$("#submit2").click(function(){
        if($("#nombre_modi").val() == "" || $("#sueldo_modi").val() == "" || $("#fecha_modi").val() == ""){
            alert("Por favor complete todos los campos. (PDF opcional)");
        }
        else{
            Modificar();
            $("#FormModi").css("visibility", "hidden");
            $("#FormModi").css("pointer-events", "none");
            $("#ContenidoMedio").css("opacity", "1");
            $("#ContenidoMedio").css("pointer-events", "all");
            $("#ordenYbotones").css("opacity", "1");
            $("#ordenYbotones").css("pointer-events", "all");
            $("#totalRegistros").css("opacity", "1");
            $("#totalRegistros").css("pointer-events", "all");
            $("#cuerpoTabla").css("opacity", "1");
            $("#cuerpoTabla").css("pointer-events", "all");
            document.getElementById("ModiForm").reset();
        }
});
$("#cargar").click(function(){
    cargaTabla();
});
$("#vaciar").click(function(){
    $("#cuerpoTabla").empty();
    $("#totalRegistros").empty();
})

function cargaTabla(){
    $("#cuerpoTabla").empty();
    $("#cuerpoTabla").html("<h2>Esperando respuesta...</h2>");
    var objAjax = $.ajax({
            type:"post",
            url:"./salidaEmpleados.php",
            data: {
                f_ID: $("#f_ID").val(),
                f_Nombre: $("#f_Nombre").val(),
                f_Area: $("#f_Area").val(),
                f_Sueldo: $("#f_Sueldo").val(),
                f_Fecha: $("#f_Fecha").val(),
                orden: $("#orden").val()
            },
            success:function(respuestaDelServer){
                $("#cuerpoTabla").empty();
                objJson = JSON.parse(respuestaDelServer);
                objJson.empleados.forEach(function(Valor){
                    var objTr = document.createElement("tr");
                    var objTd = document.createElement("td");
                    objTd.setAttribute("campo-dato","ID");
                    objTd.innerHTML = Valor.ID;
                    objTr.appendChild(objTd);
                    objTd = document.createElement("td");
                    objTd.setAttribute("campo-dato","Nombre");
                    objTd.innerHTML = Valor.Nombre;
                    objTr.appendChild(objTd);
                    objTd = document.createElement("td");
                    objTd.setAttribute("campo-dato","Area");
                    objTd.innerHTML = Valor.Area;
                    objTr.appendChild(objTd);
                    objTd = document.createElement("td");
                    objTd.setAttribute("campo-dato","Sueldo");
                    objTd.innerHTML = Valor.Sueldo;
                    objTr.appendChild(objTd);
                    objTd = document.createElement("td");
                    objTd.setAttribute("campo-dato","Fecha");
                    objTd.innerHTML = Valor.Fecha;
                    objTr.appendChild(objTd);
                    objTd = document.createElement("td");
                    objTd.setAttribute("campo-dato","Docu");
                    objTd.innerHTML = "<button class='btCelda'>PDF</button>";
                    objTd.onclick=function(){
                        $("#VentanaPDF").css("visibility", "visible");
                        $("#VentanaPDF").css("pointer-events", "all");
                        $("#ContenidoMedio").css("opacity", "0.3");
                        $("#ContenidoMedio").css("pointer-events", "none");
                        $("#ordenYbotones").css("opacity", "0.3");
                        $("#ordenYbotones").css("pointer-events", "none");
                        $("#totalRegistros").css("opacity", "0.3");
                        $("#totalRegistros").css("pointer-events", "none");
                        $("#cuerpoTabla").css("opacity", "0.3");
                        $("#cuerpoTabla").css("pointer-events", "none");
                        verPDF(Valor.ID);
                    }
                    objTr.appendChild(objTd);
                    objTd = document.createElement("td");
                    objTd.setAttribute("campo-dato","Modi");
                    objTd.innerHTML = "<button class='btCelda'>Modi</button>";
                    objTd.onclick=function(){
                        $("#FormModi").css("visibility", "visible");
                        $("#FormModi").css("pointer-events", "all");
                        $("#ContenidoMedio").css("opacity", "0.3");
                        $("#ContenidoMedio").css("pointer-events", "none");
                        $("#ordenYbotones").css("opacity", "0.3");
                        $("#ordenYbotones").css("pointer-events", "none");
                        $("#totalRegistros").css("opacity", "0.3");
                        $("#totalRegistros").css("pointer-events", "none");
                        $("#cuerpoTabla").css("opacity", "0.3");
                        $("#cuerpoTabla").css("pointer-events", "none");
                        completaFicha(Valor.ID);
                    }
                    objTr.appendChild(objTd);
                    objTd = document.createElement("td");
                    objTd.setAttribute("campo-dato","Baja");
                    objTd.innerHTML = "<button class='btCelda'>Baja</button>";
                    objTd.onclick=function(){
                        if((confirm("Seguro que desea dar de baja a " + Valor.Nombre + "?")) == true){
                            DarDeBaja(Valor.ID);
                        }
                    }
                    objTr.appendChild(objTd);

                    $("#cuerpoTabla").append(objTr);
                });
                $("#totalRegistros").html("<h2>Nro de Registros: " + objJson.empleados.length);
            }
    });
}

function completaFicha(id){
    var objAjax = $.ajax({
        type:"get",
        url:"./salidaEmpleado.php",
        data: {ID:id},
        success:function(respuestaDelServer){
            objetoDato = JSON.parse(respuestaDelServer);
            $("#id_modi").val(objetoDato.ID);
            $("#nombre_modi").val(objetoDato.Nombre);
            $("#area_modi").val(objetoDato.Area);
            $("#sueldo_modi").val(objetoDato.Sueldo);
            $("#fecha_modi").val(objetoDato.Fecha);
        }
    });
}
function llenaAreas(){
    var objAjax = $.ajax({
        url:"./salidaAreas.php",
        success:function(respuestaDelServer){
            var objetoJSON = JSON.parse(respuestaDelServer);
            objetoJSON.forEach(function(Valor){
                var objOption = document.createElement("option");
                objOption.innerHTML = Valor;
                var objOption2 = document.createElement("option");
                objOption2.innerHTML = Valor;
                $("#area").append(objOption);
                $("#area_modi").append(objOption2);
            })
        }
    });
}

function verPDF(id){
    var objAjax = $.ajax({
        type:"get",
        url:"./salidaPDF.php",
        data: {ID:id},
        success:function(respuestaDelServer){
            var objetoDato = JSON.parse(respuestaDelServer);
            $("#ContenidoPDF").html("<iframe width='100%' height='315px' src='data:application/pdf;base64,"+objetoDato.PDF+"'></iframe>");
            $("#ContenidoRespuesta").html("<h2>"+objetoDato.respuesta_estado+"</h2>");
            $("#VentanaRespuesta").css("visibility", "visible");
            $("#VentanaRespuesta").css("pointer-events", "all");
            setTimeout(() => {
                $("#VentanaRespuesta").css("visibility", "hidden");
                $("#VentanaRespuesta").css("pointer-events", "none");
            }, 5000);
        }
    });
}

function DarDeBaja(id){
    var objAjax = $.ajax({
        type:"get",
        url:"./Baja.php",
        data: {ID:id},
        success:function(respuestaDelServer){
            cargaTabla();
            var objetoJSON = JSON.parse(respuestaDelServer);
            $("#ContenidoRespuesta").html("<h4>"+objetoJSON+"</h4>");
            $("#VentanaRespuesta").css("visibility", "visible");
            $("#VentanaRespuesta").css("pointer-events", "all");
            setTimeout(() => {
                $("#VentanaRespuesta").css("visibility", "hidden");
                $("#VentanaRespuesta").css("pointer-events", "none");
            }, 6000);
        }
    });
}

function DarDeAlta(){
    var data = new FormData($("#AltasForm")[0]);
    var objAjax = $.ajax({
        type:"post",
        method:"post",
        enctype: "multipart/form-data",
        url:"./Alta.php",
        processData: false,
        contentType: false,
        cache: false,
        data: data,
        success:function(respuestaDelServer){
            var objetoJSON = JSON.parse(respuestaDelServer);
            $("#ContenidoRespuesta").html("<h4>"+objetoJSON+"</h4>");
            $("#VentanaRespuesta").css("visibility", "visible");
            $("#VentanaRespuesta").css("pointer-events", "all");
            cargaTabla();
            setTimeout(() => {
                $("#VentanaRespuesta").css("visibility", "hidden");
                $("#VentanaRespuesta").css("pointer-events", "none");
            }, 12000);
        }
    });
}

function Modificar(){
    var data = new FormData($("#ModiForm")[0]);
    var objAjax = $.ajax({
        type:"post",
        method:"post",
        enctype: "multipart/form-data",
        url:"./Modi.php",
        processData: false,
        contentType: false,
        cache: false,
        data: data,
        success:function(respuestaDelServer){
            var objetoJSON = JSON.parse(respuestaDelServer);
            $("#ContenidoRespuesta").html("<h4>"+objetoJSON+"</h4>");
            $("#VentanaRespuesta").css("visibility", "visible");
            $("#VentanaRespuesta").css("pointer-events", "all");
            cargaTabla();
            setTimeout(() => {
                $("#VentanaRespuesta").css("visibility", "hidden");
                $("#VentanaRespuesta").css("pointer-events", "none");
            }, 10000);
        }
    });
}

/*
Ventana de estado: front, back y js.
chequear validez del formulario para habilitar boton.
*/