<?php
 
$servidor = "localhost";
$usuario  = "root";
$senha    = "admin";
$banco    = "login";
 
//conecta-se ao banco de dados Mysql
$con = new mysqli($servidor, $usuario, $senha, $banco); 

//CASO HAJA ERRO NA CONEXAO, ALERTAR
if (mysqli_connect_errno()) {
    die('Não foi possível conectar-se ao banco de dados: ' . mysqli_connect_error());
    exit();
}

if(isset($_POST['buscar'])){
	$q = $_POST['consulta'];
	$query_Busca = "SELECT * FROM login WHERE login='$q'";	
	$Busca = $con->query($query_Busca) or die($con->error);
	//$row_Busca = mysqli_fetch_assoc($Busca);
	$totalRows_Busca = $Busca->num_rows;
	
} else {
	$query = "SELECT * FROM `login`";
	$Busca = $con->query($query) or die($con->error);
	$row_Busca = mysqli_fetch_array($Busca);
	$totalRows_Busca = $Busca->num_rows;
}
?>