<?php
include("function.php");
makeFichier($_POST['design'], $_POST['eco'], $_POST['be'], $_POST['soc'], $_POST['eng'], $_POST['prod'], $_POST['prix'], $_POST['dv-min'], $_POST['capa']);
?>
<!DOCTYPE html>

<html>
	<head>
		<?php include("header.php"); ?>
	</head>

	<!-- Contenu du site -->
	<body>

		<!-- <meta http-equiv="Refresh" content="5;url=comming.php" /> -->

		<!-- Centre de la page -->
		<div class="container-fluid">
			<div class="row">
				<div class="col-8 col-md-8 offset-md-2 offset-2">
        			<br/>
        			<h1 style="margin-bottom:50px; margin-top:50px; border-bottom:1px solid #CCC; padding-bottom:20px;"><i class="fas fa-align-justify"></i> Choix des critères</h1>
	        			<table class="table table-striped table-bordered">
                			<thead>
                    			<tr>
                		        	<td><b>Nom du critère</b></td>
                                	<td><b>Valeur</b></td>
                        		</tr>
                        	</thead>
                        	<tbody>
                        		<tr>
                		        	<td>Design</td>
                        			<td><?php echo $_POST['design'];?></td>
                    			</tr>

                    			<tr>
                		        	<td>Écologie</td>
                        			<td><?php echo $_POST['eco'];?></td>
                    			</tr>

                    			<tr>
                		        	<td>Bien-Être</td>
                        			<td><?php echo $_POST['be'];?></td>
                    			</tr>

                    			<tr>
                		        	<td>Social</td>
                        			<td><?php echo $_POST['soc'];?></td>
                    			</tr>

                    			<tr>
                		        	<td>Engagement</td>
                        			<td><?php echo $_POST['eng'];?></td>
                    			</tr>

                    			<tr>
                		        	<td>Productivité</td>
                        			<td><?php echo $_POST['prod'];?></td>
                    			</tr>

                    			<tr>
                		        	<td>Prix</td>
                        			<td><?php echo $_POST['prix'];?>€</td>
                    			</tr>

                    			<tr>
                		        	<td>Durée de vie minimale</td>
                        			<td><?php echo $_POST['dv-min'];?></td>
                    			</tr>

                    			<tr>
                		        	<td>Capacité</td>
                        			<td><?php echo $_POST['capa'];?> personnes</td>
                    			</tr>
                        	</tbody>
        			</table>
    			</div>
			</div>	
		</div>
	</body>
</html>