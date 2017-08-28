<html>

<head>
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
echo "Conecto no Banco!"; 
?>
<br /><br />
<?php
//tabela dell
$fabricante=$_POST['fabricante'];
$modelo=$_POST['modelo'];
$tipo=$_POST['tipo'];

//Data Envio convertida para o Mysql
$data = $_POST['data'];
echo date('d-m-Y', strtotime($data));

$data = date("Y-m-d",strtotime(str_replace('/','-',$data)));  
echo date('Y-m-d', strtotime($data));

$url=$_POST['url'];
$serie=$_POST['serie'];
$proprietario=$_POST['proprietario'];
$origem=$_POST['origem'];

//Data Garantia convertida para o Mysql
$venc_garantia = $_POST['venc_garantia'];
echo date('d-m-Y', strtotime($venc_garantia));

$venc_garantia = date("Y-m-d",strtotime(str_replace('/','-',$venc_garantia))); 
echo date('Y-m-d', strtotime($venc_garantia));

$tipo_instalacao=$_POST['tipo_instalacao'];
$configuracao=$_POST['configuracao'];
$uname_a=$_POST['uname_a'];
$instalacao=$_POST['instalacao'];
$status=$_POST['status'];
$servicos=$_POST['servicos'];

//tabela equipamento
$descricao=$_POST['descricao'];
$quantidade=$_POST['quantidade'];
$tombamento=$_POST['tombamento'];
$local=$_POST['local'];

//tabela equipamento
$query = "INSERT INTO equipamento (item, tipo, descricao, quantidade, tombamento, local, status) 
VALUES(NULL, '$tipo', '$descricao', '$quantidade', '$tombamento', '$local', '$status')";
$mysqli->query($query);

printf ("Registro de id %d.\n\n", $mysqli->insert_id);

//tabela dell
$query2 = "INSERT INTO dell (id_item, fabricante, modelo, tipo, data, url, serie, proprietario, origem, venc_garantia, tipo_instalacao,
configuracao, uname_a, instalacao, servicos, tombamento) VALUES(LAST_INSERT_ID(), '$fabricante', '$modelo', 
'$tipo', '$data', '$url', '$serie', '$proprietario', '$origem', '$venc_garantia', '$tipo_instalacao', '$configuracao', 
'$uname_a', '$instalacao', '$servicos', '$tombamento')";
$mysqli->query($query2);


printf("Novo Registro foi inserido com sucesso\n\n\n"); 
printf ("Registro de id %d.\n\n\n", $mysqli->insert_id);


?>
<br /><br />
<br /><br />

Click aqui para retornar: <input name="cadastro_dell" type="button" 
onClick="location.href='http://localhost/cadastro'" value="Retornar">
</body>

</html>