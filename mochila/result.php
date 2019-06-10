<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
<input type="submit" name="" value="resultado" id="boton1" onclick = "evaluar();">
</body>
</html>

<?php

function mostrarTexto($texto) {

echo "<strong>El texto a mostrar es el siguiente: </strong>";
echo $texto;
}

mostrarTexto("Me gusta mucho la web de aprenderaprogramar.com");

//Fin de declaración de funciones

$array_peso = array(12, 12, 23, 14, 25,11);
$array_ganancia=array(20, 20, 40, 50, 60,22);
$numero_objetos=count($array_peso);
echo "$numero_objetos";
$capacidad=200;


function evaluar ($capacidad, $array_peso, $array_ganancia, $numero_objetos){

	for ($i=1; $i <= $numero_objetos; $i++) {
		if ($array_peso[$i] > $capacidad) {
			$array_ganancia[$i] = 0;
		}

		$array_poblacion[$i] = sprintf('%1$0'.$numero_objetos.'b',$i);
		echo "<tr><td>".$array_peso[$i]."</td> <td>".$array_ganancia[$i]."</td><td>".$array_poblacion[$i]."</td></tr>";
		@$suma = $suma + $array_ganancia[$i];
	}
	echo"</table></div>";
	$porcentaje = 100/$suma;

	for ($i=1; $i <= $numero_objetos; $i++) {
		$array_porcentaje[$i] = $porcentaje * $array_ganancia[$i];
	}

	for($j=1; $j<=2; $j++){
		$random = rand(0, 100);
		echo"<script> alert('Ruleta:".$random."');</script>";
		$suma2 = 0;
		for ($i=1; $i <= $numero_objetos; $i++) {
			if ($array_ganancia[$i] == 0) {
				
			}

			else{
				$suma2 = $suma2 + $array_porcentaje[$i];
				
				if ($random <= $suma2) {
					$array_elegido[$j] = $array_poblacion[$i];
					break;
					}
				else{

					}
				}
		}
		
	}

	?>
	<div id='resultados'>
	<div id="elegidos">
		<h3> Elegidos</h3>

	<?php
	for($j=1; $j<=2; $j++){
		echo"<p>".$array_elegido[$j]."</p>";
	}

	$genes = preg_split('//', $array_elegido[1], -1, PREG_SPLIT_NO_EMPTY);
	$genes2 = preg_split('//', $array_elegido[2], -1, PREG_SPLIT_NO_EMPTY);

	$aux = $genes[2];
	$genes[2] = $genes2[2];
	$genes2 = $aux;

	echo"<p>Optimo:</p>";
	foreach ($genes as $key) {
		echo"".$key."";
	}
	echo"</div></div>";
}

	
?>