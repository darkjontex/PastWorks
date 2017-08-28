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
<label for="consulta">Digite numero do iSNB ou titulo:</label>
<input type="text" id="consulta" name="consulta" maxlength="255" />
<input name="buscar" type="submit" id="buscar" value="BUSCAR" />
</fieldset>
</form>
<table width="100%" border="1">
  <tr class="tabela">
    <td>iSNB:</td>
    <td>Titulo:</td>
    <td>Ano:</td>
    <td>Descri&ccedil;&aring;o:</td>
    <td>Autor:</td>
    <td>Localidade:</td>
	 <td>Quantidade:</td>
  </tr>
  <?php while($row_Busca = mysqli_fetch_array($Busca)){ ?>
  <tr>
    <td><?php echo $row_Busca['isnb']; ?></td>
    <td><?php echo $row_Busca['titulo']; ?></td>
    <td><?php echo $row_Busca['ano']; ?></td>
    <td><?php echo $row_Busca['descricao']; ?></td>
    <td><?php echo $row_Busca['autor']; ?></td>
    <td><?php echo $row_Busca['local']; ?></td>
	<td><?php echo $row_Busca['quantidade']; ?></td>
  </tr>
  <?php }   ?>
</table>
<p>&nbsp;</p>


</body>



</html>