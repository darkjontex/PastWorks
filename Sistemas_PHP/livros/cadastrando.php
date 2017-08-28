<html>

<head>
<link rel="stylesheet" type="text/css" href="/livros/css/cadastro.css">
<title>Cadastrando...</title>
</head>


<body>
<?php
$host = "localhost";
$user = "root";
$pass = "admin";
$banco = "livros";
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
$isnb=$_POST['isnb'];
$titulo=$_POST['titulo'];
$ano=$_POST['ano'];
$descricao=$_POST['descricao'];
$autor=$_POST['autor'];
$local=$_POST['local'];
$quantidade=$_POST['quantidade'];



$query = "INSERT INTO livro VALUES('$isnb', '$titulo', '$ano', '$descricao', '$autor', '$local', '$quantidade')";
$mysqli->query($query);

printf("Novo Registro foi inserido com sucesso.\n"); 
printf ("Registro de isnb ");
echo $query;

$mysqli->close();
?>
<br /><br />

Click aqui para retornar: <input name="cadastro" type="button" 
onClick="location.href='../livros'" value="Retornar" class="botao">
</body>

</html>