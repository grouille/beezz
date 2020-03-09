<?php
$MAX_POINT = 12;
$POINTS = 0;
$DESIGN = 0;
$ECOLOGIE = 0;
$BIENETRE = 0;
$SOCIAL = 0;
$ENGAGEMENT = 0;
$PRODUCTIVITE = 0;
$PRIX = 9000;
$DV_MIN = "2 Semaines";
$CAPACITE = 2;
$fichier = fopen("solutions.txt", "w");
fclose($fichier);
?>

<!DOCTYPE html>

<html>
	<head>
		<link rel="stylesheet" href="css/intro.css">
		<?php include("header.php"); ?>
	</head>

	<!-- Contenu du site -->
	<body>
		<div id="bloc_page">
            <!-- L'astuce --------------------->
            <div id="invisible">
            </div>
            <!--------------------------------->
            <div id="logoStart">
                <img src="img/logo-combine.png" style="width: 100%; height: auto;" alt="Logo">
                <br/>
                <br/>
                <form action="accueil.php" method="post">
                	<?php include("hidden.php");?>
                	<input type="submit" class="btn btn-light" value="Accéder au site"/>
				</form>
                <!-- <meta http-equiv="Refresh" content="5;url=accueil.php" /> -->
            </div>
        </div>
	</body>
</html>