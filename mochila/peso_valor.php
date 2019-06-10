<!DOCTYPE html>
<html>
<head>
	<title>PROBLEMA DE LA MOCHILA</title>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js"></script> 
    <link rel="stylesheet" href="css/bootstrap.min.css" media="screen">
	<link rel="stylesheet" href="centrar.css">

<script>
 /*Funcion de Capturar, Almacenar datos y Limpiar campos*/
$(document).ready(function(){    
    $('#boton-guardar').click(function(){        
        /*Captura de datos escrito en los inputs*/        
        var cap = document.getElementById("capacidadtxt").value;
        /*Guardando los datos en el LocalStorage*/
        localStorage.setItem("Capacidad", cap);
        /*Limpiando los campos o inputs*/
        document.getElementById("capacidadtxt").value = "";
        });   
});

/*Funcion Cargar y Mostrar datos*/
$(document).ready(function(){    
    $('#boton-cargar').click(function(){                       
        /*Obtener datos almacenados*/
        var capacidad = localStorage.getItem("Capacidad");
        /*Mostrar datos almacenados*/      
        document.getElementById("capacidad").innerHTML = capacidad;
        
    });   
});

</script>

</head>
<body>
<header>
<center><div class="container">
		<h1>
		<br>
			<strong>
				PROBLEMA DE LA MOCHILA
			</strong>
		</br>
		</h1>
	</div></center>
	
</header>


<center><p1>Capacidad de la mochila</p1>
              
<input type="text" placeholder="Capacidad" id="capacidadtxt"> <br>  <br>   
<button id="boton-guardar">Guardar</button><br>

<hr />
Capacidad:
<label type="text" id="capacidad"></label><br>                          


<button id="boton-cargar">
Cargar elementos
</button>
</center>

<hr />

<center>
	<form method="POST" action="moch.php">
<?php 
if(isset($_POST['Siguiente']))
	$cantidad=$_POST['nvalor'];	
	for ($i=1; $i<=$cantidad; $i++) { ?>
		<label for="peso[]">Peso: </label>
		<input type="text" name="peso[]"><br>
		<label for="valor[]">Valor: </label>
		<input type="text" name="valor[]"><br>
	
<?php } ?>
<input type="submit" name="Siguiente" value = "Siguiente">
</form>
	<br>
</center>



</body>
</html>