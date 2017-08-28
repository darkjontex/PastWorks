<html>

<head>
<title></title>
<style type="text/css">
.tabela {
	font-weight: bold;
}
</style>
</head>


<body>
<?php
include 'php/busca.php';
?>

<form name="formBusca" method="post" action="consulta.php">
<fieldset>
<label for="consulta">Digite o login para busca:</label>
<input type="text" id="consulta" name="consulta" maxlength="255" />
<input name="buscar" type="submit" id="buscar" value="BUSCAR" />
</fieldset>
</form>
<table width="100%" border="1">
  <tr class="tabela">
    <td>Nome:</td>
    <td>Login:</td>
    <td>Senha:</td>
  </tr>
  <?php while($row_Busca = mysqli_fetch_array($Busca)){ ?>
  <tr>
    <td><?php echo $row_Busca['nome']; ?></td>
    <td><?php echo $row_Busca['login']; ?></td>
    <td><?php echo $row_Busca['senha']; ?></td>    
  </tr>
  <?php }   ?>
</table>
<p>&nbsp;</p>


</body>



</html>