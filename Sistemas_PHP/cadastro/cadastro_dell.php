<html>

<head>
<script src="/cadastro/javascript/jquery-1.5.2.min.js" type="text/javascript"></script>
<script src="/cadastro/javascript/jquery.maskedinput.min.js" type="text/javascript"></script>
<link rel="stylesheet" type="text/css" href="/cadastro/css/cadastro_dell.css">

<script>
jQuery(function($){
   $("#data").mask("99/99/9999",{placeholder:" "});
   $("#venc_garantia").mask("99/99/9999",{placeholder:" "});
});
</script>

<title></title>
</head>
<div class="cadastrodell">Cadastro padr&atilde;o clicar aqui:</div><div class="retorna">Retornar click aqui: </div><input name="retorna" type="button" 
onClick="location.href='../cadastro/cadastro.php'" value="cadastro padr&atilde;o" class="botao1"> <input name="retorna" type="button" 
onClick="location.href='../cadastro/index.php'" value="retornar" class="botao2"><br /><br />

<body>
<label class="aviso">Os campos em vermelho s&atilde;o obrigat&oacute;rios</label><br /><br />
<form name="signup" method="post" action="cadastrando_dell.php"> 
Fabricante: <input type="text" name="fabricante" maxlength="10" class="campos"/> &nbsp;&nbsp;
Modelo: <input type="text" name="modelo" maxlength="50" class="campos"/> &nbsp;&nbsp;
Tipo: <input type="text" name="tipo" maxlength="50" class="campos"/> &nbsp;&nbsp;
Numero de serie: <input type="text" name="serie" maxlength="12" class="campos"/> <br /><br />
Data de Envio(dia/mes/ano): <input type="text" name="data" id="data" class="campos"/> &nbsp;&nbsp;
Venc. Garantia(dia/mes/ano): <input type="text" name="venc_garantia" id="venc_garantia" class="importante"/> &nbsp;&nbsp;
Proprietario: <input type="text" name="proprietario" maxlength="30" class="campos"/> <br /><br />
Origem: <input type="text" name="origem" maxlength="30" class="campos"/> &nbsp;&nbsp;
Situa&ccedil;&atilde;o (status): <input type="text" name="status" maxlength="15" class="campos"/> &nbsp;&nbsp;
Tipo de Instala&ccedil;&atilde;o (fisica ou logica): <input type="text" name="tipo_instalacao" maxlength="30" class="campos"/> <br /><br />
URL DELL: <input type="text" name="url" maxlength="100" class="campos" size="100"/> <br /><br />
Configura&ccedil;&atilde;o: <input type="text" name="configuracao" maxlength="150" class="campos" size="100"/> <br /><br />
uname_a: <input type="text" name="uname_a" maxlength="100" class="campos" size="100"/> <br /><br />
Instala&ccedil;&atilde;o: <input type="text" name="instalacao" maxlength="250" class="campos" size="100"/> <br /><br />
Servi&ccedil;os: <input type="text" name="servicos" maxlength="150" class="campos" size="100"/> <br /><br />
Descri&ccedil;&atilde;o: <input type="text" name="descricao" maxlength="150" class="campos" size="100"/> <br /><br />
Quantidade: <input type="text" name="quantidade" maxlength="5" class="campos" size="3"/> <br />
Numero de Tombamento: <input type="text" name="tombamento" maxlength="13" class="importante" size="13"/> <br />
Local de Uso: <input type="text" name="local" maxlength="20" class="campos" size="20"/> <br />

<input type="submit" value="Cadastrar DELL" name="botao" class="botao3"/>
</form>

<?php

	if(isset($_POST["botao"])){
		if(empty($venc_garantia) || empty($tombamento) || empty($status)){
				echo "Preencha todos os campos!";			
		}
	}
?>		
</body>
</html>