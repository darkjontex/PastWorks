<html>


<head>
<script src="/cadastro/javascript/jquery-1.5.2.min.js" type="text/javascript"></script>
<script src="/cadastro/javascript/jquery.maskedinput.min.js" type="text/javascript"></script>
<link rel="stylesheet" type="text/css" href="/cadastro/css/cadastro.css">
<title></title>
</head>

<body>


<form name="signup" method="post" action="cadastrando.php"> 
<div class="topo">&nbsp;</div><br /><br />
Tipo de Equipamento: <input type="text" name="tipo" maxlength="80" class="importante" size="80"/> <br /><br />
Descricao: <input type="text" name="descricao" maxlength="150" size="150"/> <br /><br />
Quantidade: <input type="text" name="quantidade" maxlength="3" size="3"/> <br /><br />
Numero de Tombamento: <input type="text" name="tombamento" maxlength="13" class="importante" size="13"/> <br /><br />
Local de Uso: <input type="text" name="local" maxlength="20" class="importante" size="20"/> <br /><br />
Situacao(status): <input type="text" name="status" maxlength="15" class="importante" size="15"/> <br /><br />

<input type="submit" value="Cadastrar" class="botao"/>
<input name="retorna" type="button" 
onClick="location.href='../cadastro/index.php'" value="retornar" class="botao">
</form>
<?php	
	if(isset($_POST["botao"])){
			echo "botão foi clicado";

		if(empty($tipo) || empty($tombamento) || empty($status)){
				echo "Preencha todos os campos!";			
		}
	}
?>		

</body>

</html>