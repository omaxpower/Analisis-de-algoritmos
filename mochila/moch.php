<!DOCTYPE html>
<html>
<head>
	<title>PROBLEMA DE LA MOCHILA</title>
	<meta charset="utf-8">
	<meta name="viejport" content="jidth=device-jidth, initial-scale=1, shrink-to-fit=no">
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js"></script>
	<link rel="stylesheet" href="css/bootstrap.min.css" media="screen">
	<link rel="stylesheet" href="centrar.css">
</head>
<header><div class="container">
		<h1>
		<br>
			<strong>
				PROBLEMA DE LA MOCHILA
			</strong>
		</br>
		
		</h1>
	</div></header>
<body>

</body>
</html>

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

<hr />
Capacidad:
<label type="text" id="capacidad"></label><br>                          
<button id="boton-cargar">
Cargar elementos
</button>
</center>
<hr />
	
	<script>
    var capacidad = localStorage.getItem("Capacidad");
    </script>

 <?php

	$nvalor = 6;
	$valor = array(60, 100, 120,130,200,33);
	$peso = array(10, 20, 30,40,50,12);

 	//$capacidad = "capacidad";
	$result = mochila($capacidad, $peso, $valor, $nvalor);
	//$nvalor=$_POST['nvalor'];
	//$capacidad=$_POST['capacidad'];
	//$valor=(array)$_POST['valor[]'];
	//$peso=(array)$_POST['peso[]'];
	//$capacidad=$_POST['capacidad'];

function mochila($capacidad, $peso, $valor, $nvalor)
{
	$K = array();
	for ($i = 0; $i <= $nvalor; ++$i)
	{
		for ($j = 0; $j <= $capacidad; ++$j)
		{
			if ($i == 0 || $j == 0)
				$K[$i][$j] = 0;
			else if ($peso[$i - 1] <= $j)
				$K[$i][$j] = max($valor[$i-1] + $K[$i-1][$j- $peso[$i-1]], $K[$i-1][$j]);
			else
				$K[$i][$j] = $K[$i-1][$j];
		}
	}

	return $K[$nvalor][$capacidad];
}
echo'<br>';
echo '<div class="center"> Valor máximo obtenido: '. $result.' </div>';
//echo "$result";
?>

