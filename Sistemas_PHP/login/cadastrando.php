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
$banco = "login";
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
$nome=$_POST['nome'];
$login=$_POST['login'];
$senha=$_POST['senha'];

$query = "INSERT INTO login VALUES('$nome', '$login', '$senha')";
$mysqli->query($query);

printf("Novo Registro de Login e Senha foi inserido com sucesso.\n"); 
printf ("Registro de login ");
echo $nome," ";
echo $login," ";
echo "**********";

$mysqli->close();
?>
<br /><br />

Click aqui para retornar: <input name="cadastro" type="button" 
onClick="location.href='../login'" value="Retornar" class="botao">
</body>

</html>