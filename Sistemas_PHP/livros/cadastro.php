<html>


<head>
<script src="/livros/javascript/jquery-1.5.2.min.js" type="text/javascript"></script>
<script src="/livros/javascript/jquery.maskedinput.min.js" type="text/javascript"></script>
<link rel="stylesheet" type="text/css" href="/livros/css/cadastro.css">
<title></title>
</head>

<body>

<div class="topo">&nbsp;</div><br /><br />

<form name="signup" method="post" action="cadastrando.php"> 
iSNB: <input type="text" name="isnb" maxlength="20" class="importante" size="20"/> <br /><br />
Titulo: <input type="text" name="titulo" maxlength="80" size="80" class="importante"/> <br /><br />
Ano: <input type="text" name="ano" maxlength="4" size="4" class="campos"/> <br /><br />
Descri&ccedil;&atilde;o: <input type="text" name="descricao" maxlength="150" class="campos" size="150"/> <br /><br />
Autor: <input type="text" name="autor" maxlength="100" size="100" class="campos"/> <br /><br />
Localidade: <input type="text" name="local" maxlength="50" class="importante" size="50"/> <br /><br />
Quantidade: <input type="text" name="quantidade" maxlength="3" class="campos" size="3"/> <br /><br />

<input type="submit" value="Cadastrar" class="botao"/>
<input name="retorna" type="button" 
onClick="location.href='../livros/index.php'" value="retornar" class="botao">
</form>
<?php	
	if(isset($_POST["botao"])){
			echo "botão foi clicado";

		if(empty($isnb) || empty($ano) || empty($local)){
				echo "Preencha todos os campos!";			
		}
	}
?>		

</body>

</html>