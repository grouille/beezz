<?php
$NAME = $_POST['name'];
$VALUE = $_POST['value'];
$MAX_POINT = $_POST['max'];
$POINTS = $_POST['pts'];
$DESIGN = $_POST['design'];
$ECOLOGIE = $_POST['eco'];
$BIENETRE = $_POST['be'];
$SOCIAL = $_POST['soc'];
$ENGAGEMENT = $_POST['eng'];
$PRODUCTIVITE = $_POST['prod'];
$PRIX = $_POST['prix'];
$DV_MIN = $_POST['dv-min'];
if($NAME=='design')
{
	$POINTS = $POINTS + $VALUE - $DESIGN;
	$DESIGN = $VALUE;
}
else
{
	$DESIGN = $_POST['design'];
}
if($NAME=='eco')
{
	$POINTS = $POINTS + $VALUE - $ECOLOGIE;
	$ECOLOGIE = $VALUE;
}
else
{
	$ECOLOGIE = $_POST['eco'];
}
if($NAME=='soc')
{
	$POINTS = $POINTS + $VALUE - $SOCIAL;
	$SOCIAL = $VALUE;
}
else
{
	$SOCIAL = $_POST['soc'];
}
if($NAME=='be')
{
	$POINTS = $POINTS + $VALUE - $BIENETRE;
	$BIENETRE = $VALUE;
}
else
{
	$BIENETRE = $_POST['be'];
}
if($NAME=='eng')
{
	$POINTS = $POINTS + $VALUE - $ENGAGEMENT;
	$ENGAGEMENT = $VALUE;
}
else
{
	$ENGAGEMENT = $_POST['eng'];
}
if($NAME=='prod')
{
	$POINTS = $POINTS + $VALUE - $PRODUCTIVITE;
	$PRODUCTIVITE = $VALUE;
}
else
{
	$PRODUCTIVITE = $_POST['prod'];
}
$PRIX = $_POST['prix'];
if($NAME=='prix')
{
	$PRIX = $VALUE;
}
$DV_MIN = $_POST['dv-min'];
if($NAME=='dv-min')
{
	$DV_MIN = $VALUE;
}
?>

<form action="accueil.php" method="post" id="form">
	<?php
	include("hidden.php");
	?>
</form>

<script type="text/javascript">
	document.getElementById('form').submit();
</script>