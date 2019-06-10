<!DOCTYPE html>
<html>
<head>

	<title>PROBLEMA DE LA MOCHILA</title>
	<meta charset="utf-8">
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js"></script> 
	<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
	<link rel="stylesheet" href="css/bootstrap.min.css" media="screen" />

<script>
 /*Funcion de Capturar, Almacenar datos y Limpiar campos*/
$(document).ready(function(){    
    $('#boton-guardar').click(function(){        
        /*Captura de datos escrito en los inputs*/        
        var cap = document.getElementById("nelem").value;
        /*Guardando los datos en el LocalStorage*/
        localStorage.setItem("Elementos", cap);
        /*Limpiando los campos o inputs*/
        document.getElementById("nelem").value = "";
        });   
});

/*Funcion Cargar y Mostrar datos*/
$(document).ready(function(){    
    $('#boton-cargar').click(function(){                       
        /*Obtener datos almacenados*/
        var capacidad = localStorage.getItem("Elementos");
        /*Mostrar datos almacenados*/      
        document.getElementById("nelem").innerHTML = capacidad;
        
    });   
});

</script>


</head>

<body>
<header>
<center>
	<div class="container">
		<h1>
		<br>
			<strong>
				PROBLEMA DE LA MOCHILA
			</strong>
		</br>
		
		</h1>
	</div>
</center>
</header>

<center>
	<div class="container">
		<p>
			Ingrese la cantidad de objetos: 
		</p>
	<form action="peso_valor.php" method="POST">   
	<input type="text" name="nvalor" size="10" />
	<input type="submit" name="Siguiente" value="Siguiente" />
	</form>
	
	
</center>
	
	<script src="js/jquery.js"></script>
	<script src="js/bootstra.min.js"></script>
</body>
</html>