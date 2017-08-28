<html>

<head>
<link rel="stylesheet" type="text/css" href="/cadastro/css/cadastro.css">
<title>Cadastrando...</title>
</head>


<body>
<?php
$host = "localhost";
$user = "root";
$pass = "admin";
$banco = "cadastro";
// CONECTA BANCO DE DADOS
$mysqli = new mysqli($host,$user,$pass,$banco);

//CHECA CONEXAO
if (mysqli_connect_errno()) {
    die('Não foi possível conectar-se ao banco de dados: ' . 
	mysqli_connect_error());
    exit();
}
//if(mysqli_connect_errno()) trigger_error(mysqli_connect_error());
else
echo "Sucesso!"; 
?>
<br /><br />
<?php
$tipo=$_POST['tipo'];
$descricao=$_POST['descricao'];
$quantidade=$_POST['quantidade'];
$tombamento=$_POST['tombamento'];
$local=$_POST['local'];
$status=$_POST['status'];


$query = "INSERT INTO equipamento VALUES(NULL, '$tipo', '$descricao', '$quantidade', '$tombamento', '$local', '$status')";
$mysqli->query($query);

printf("Novo Registro foi inserido com sucesso.\n"); 
printf ("Registro de tombamento ");
echo $tombamento;

$mysqli->close();
?>
<br /><br />

Click aqui para retornar: <input name="cadastro_dell" type="button" 
onClick="location.href='../cadastro'" value="Retornar" class="botao">
</body>

</html>