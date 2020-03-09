<?php
exec( '"C:\\wamp64\\www\\beezz\\projet_beezz.exe"' );
header('Location: resultat.php');
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
                <img src="img/logo-combine.png" alt="Logo">
                <br/>
                <br/>
                <h1 style="margin-bottom:50px; margin-top:50px; border-bottom:1px solid #CCC; padding-bottom:20px; text-align: center; color:#FFF;">Veuillez patienter, votre cabine est en cours de construction...</h1>
            </div>
        </div>
	</body>
</html>