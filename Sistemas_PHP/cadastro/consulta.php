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
<label for="consulta">Digite numero de Tombamento:</label>
<input type="text" id="consulta" name="consulta" maxlength="255" />
<input name="buscar" type="submit" id="buscar" value="BUSCAR" />
</fieldset>
</form>
<table width="100%" border="1">
  <tr class="tabela">
    <td>item:</td>
    <td>Tombamento:</td>
    <td>Tipo:</td>
    <td>Descri&ccedil;&aring;o:</td>
    <td>Quantidade:</td>
    <td>Local de uso:</td>
    <td>Status:</td>
  </tr>
  <?php while($row_Busca = mysqli_fetch_array($Busca)){ ?>
  <tr>
    <td><?php echo $row_Busca['item']; ?></td>
    <td><?php echo $row_Busca['tombamento']; ?></td>
    <td><?php echo $row_Busca['tipo']; ?></td>
    <td><?php echo $row_Busca['descricao']; ?></td>
    <td><?php echo $row_Busca['quantidade']; ?></td>
    <td><?php echo $row_Busca['local']; ?></td>
    <td><?php echo $row_Busca['status']; ?></td>
  </tr>
  <?php }   ?>
</table>
<p>&nbsp;</p>


</body>



</html>