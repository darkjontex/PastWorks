<html>


<head>
<script src="/login/javascript/jquery-1.5.2.min.js" type="text/javascript"></script>
<script src="/login/javascript/jquery.maskedinput.min.js" type="text/javascript"></script>
<link rel="stylesheet" type="text/css" href="/login/css/cadastro.css">
<title></title>
</head>

<body>

<div class="topo">&nbsp;</div><br /><br />

<form name="signup" method="post" action="cadastrando.php"> 
Nome: <input type="text" name="nome" maxlength="80" class="campos" size="80"/>(Max. 80 carac.) <br /><br />
Login: <input type="text" name="login" maxlength="30" size="30" class="importante"/> (Max. 30 carac.)<br /><br />
Senha: <input type="password" name="senha" maxlength="30" size="30" class="importante"/> (Max. 30 carac.)<br /><br />

<input type="submit" value="Cadastrar" class="botao"/>
<input name="retorna" type="button" 
onClick="location.href='../login/index.php'" value="retornar" class="botao">
</form>
<?php	
	if(isset($_POST["botao"])){
			echo "botão foi clicado";

		if(empty($nome) || empty($login) || empty($senha)){
				echo "Preencha todos os campos!";			
		}
	}
?>		

</body>

</html>