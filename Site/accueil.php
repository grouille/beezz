<?php
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
$RESTE = $MAX_POINT - $POINTS;
?>

<!DOCTYPE html>

<html>
	<head>
		<?php include("header.php"); ?>
	</head>

	<!-- Contenu du site -->
	<body>

		<!-- Centre de la page -->
		<div class="container-fluid">
			<div class="row">
				<div class="col-8 col-md-8 offset-md-2 offset-2">
        			<br/>
        			<h1 style="margin-bottom:50px; margin-top:50px; border-bottom:1px solid #CCC; padding-bottom:20px;"><i class="fas fa-align-justify"></i> Choix des critères</h1>
        			<h2 style="margin-bottom:50px; margin-top:50px; border-bottom:1px solid #CCC; padding-bottom:20px;">Critères à points (<?php echo $RESTE;?> restants)</h2>
	        			<table class="table table-striped table-bordered">
                			<thead>
                        			<tr>
                        		        	<td><b>Critère</b></td>
                                			<td><b>Valeur</b></td>
                                			<td><b>Choix</b></td>
                                			<td><b>Action</b></td>
                        			</tr>
                        	</thead>
                        	<tbody>
                        			<div id="values">
                        				<tr>
                        					<form action="send.php" method="post">
                        						<input type="hidden" name="name" value="design" />
												<?php include("hidden.php");?>
	                        					<td><label for="design"><img src="img/design.png" class="mr-3" alt="design" width="60" height="70"></label></td>

												<td><br/>
													<div class="my-1 mr-sm-2">
													    <select class="custom-select my-1 mr-sm-2" id="desgin" name="value">
													     	<?php
													     	$R = ($RESTE+$DESIGN > 4) ? 4 : $RESTE+$DESIGN;
														    for($i = 0; $i<=$R; $i++)
														    { ?>
														    	<option><?php echo $i;?></option>
														    <?php }?>
													    </select>
													</div>
												</td>

												<td><br/><?php echo $DESIGN;?></td>

												<td><br/><input type="submit" class="btn" style="background-color:#618b99 !important; color:#FFF;" value="Valider" /></td>
											</form>
                        				</tr>

                        				<tr>
                        					<form action="send.php" method="post">
                        						<input type="hidden" name="name" value="eco" />
                        						<?php include("hidden.php");?>
	                        					<td><label for="ecologie"><img src="img/ecologie.png" class="mr-3" alt="design" width="80" height="70"></label></td>

												<td><br/>
													<div class="my-1 mr-sm-2">
													    <select class="custom-select my-1 mr-sm-2" id="ecologie" name="value">
													     	<?php
														    $R = ($RESTE+$ECOLOGIE > 4) ? 4 : $RESTE+$ECOLOGIE;
														    for($i = 0; $i<=$R; $i++)
														    { ?>
														    	<option><?php echo $i;?></option>
														    <?php }?>
													    </select>
													</div>
												</td>

												<td><br/><?php echo $ECOLOGIE;?></td>

												<td><br/><input type="submit" class="btn" style="background-color:#618b99 !important; color:#FFF;" value="Valider" /></td>
											</form>
                        				</tr>

                        				<tr>
                        					<form action="send.php" method="post">
                        						<input type="hidden" name="name" value="be" />
                        						<?php include("hidden.php");?>
	                        					<td><label for="be"><img src="img/bien-etre.png" class="mr-3" alt="design" width="86" height="70"></label></td>

												<td><br/>
													<div class="my-1 mr-sm-2">
													    <select class="custom-select my-1 mr-sm-2" id="be" name="value">
													     	<?php
														    $R = ($RESTE+$BIENETRE > 4) ? 4 : $RESTE+$BIENETRE;
														    for($i = 0; $i<=$R; $i++)
														    { ?>
														    	<option><?php echo $i;?></option>
														    <?php }?>
													    </select>
													</div>
												</td>

												<td><br/><?php echo $BIENETRE;?></td>

												<td><br/><input type="submit" class="btn" style="background-color:#618b99 !important; color:#FFF;" value="Valider" /></td>
											</form>
                        				</tr>

                        				<tr>
                        					<form action="send.php" method="post">
                        						<input type="hidden" name="name" value="soc" />
                        						<?php include("hidden.php");?>
	                        					<td><label for="social"><img src="img/social.png" class="mr-3" alt="design" width="70" height="60"></label></td>

												<td><br/>
													<div class="my-1 mr-sm-2">
													    <select class="custom-select my-1 mr-sm-2" id="social" name="value">
													     	<?php
														    $R = ($RESTE+$SOCIAL > 4) ? 4 : $RESTE+$SOCIAL;
														    for($i = 0; $i<=$R; $i++)
														    { ?>
														    	<option><?php echo $i;?></option>
														    <?php }?>
													    </select>
													</div>
												</td>

												<td><br/><?php echo $SOCIAL;?></td>

												<td><br/><input type="submit" class="btn" style="background-color:#618b99 !important; color:#FFF;" value="Valider" /></td>
											</form>
                        				</tr>

                        				<tr>
                        					<form action="send.php" method="post">
                        						<input type="hidden" name="name" value="eng" />
                        						<?php include("hidden.php");?>
	                        					<td><label for="engagement"><img src="img/engagement.png" class="mr-3" alt="design" width="116" height="70"></label></td>

												<td><br/>
													<div class="my-1 mr-sm-2">
													    <select class="custom-select my-1 mr-sm-2" id="engagement" name="value">
													     	<?php
														    $R = ($RESTE+$ENGAGEMENT > 4) ? 4 : $RESTE+$ENGAGEMENT;
														    for($i = 0; $i<=$R; $i++)
														    { ?>
														    	<option><?php echo $i;?></option>
														    <?php }?>
													    </select>
													</div>
												</td>

												<td><br/><?php echo $ENGAGEMENT;?></td>

												<td><br/><input type="submit" class="btn" style="background-color:#618b99 !important; color:#FFF;" value="Valider" /></td>
											</form>
                        				</tr>

                        				<tr>
                        					<form action="send.php" method="post">
                        						<input type="hidden" name="name" value="prod" />
                        						<?php include("hidden.php");?>
	                        					<td><label for="productivite"><img src="img/productivite.png" class="mr-3" alt="design" width="122" height="70"></label></td>

												<td><br/>
													<div class="my-1 mr-sm-2">
													    <select class="custom-select my-1 mr-sm-2" id="productivite" name="value">
													     	<?php
														    $R = ($RESTE+$PRODUCTIVITE > 4) ? 4 : $RESTE+$PRODUCTIVITE;
														    for($i = 0; $i<=$R; $i++)
														    { ?>
														    	<option><?php echo $i;?></option>
														    <?php }?>
													    </select>
													</div>
												</td>

												<td><br/><?php echo $PRODUCTIVITE;?></td>

												<td><br/><input type="submit" class="btn" style="background-color:#618b99 !important; color:#FFF;" value="Valider" /></td>
											</form>
                        				</tr>
                        			</div>
                			</tbody>
        			</table>
        			<h2 style="margin-bottom:50px; margin-top:50px; border-bottom:1px solid #CCC; padding-bottom:20px;">Autres critères</h2>
	        			<table class="table table-striped table-bordered">
                			<thead>
                        			<tr>
                        		        	<td><b>Nom du critère</b></td>
                                			<td><b>Valeur</b></td>
                                			<td><b>Choix</b></td>
                                			<td><b>Action</b></td>
                        			</tr>
                        	</thead>
                        	<tbody>
                        			<div id="values">

                        				<tr>
                        					<form action="send.php" method="post">
                        						<input type="hidden" name="name" value="prix" />
                        						<?php include("hidden.php");?>
	                        					<td><label for="prix">Prix</label></td>

												<td>
													<div class="my-1 mr-sm-2">
													    <select class="custom-select my-1 mr-sm-2" id="prix" name="value">
														    <option>3000</option>
														    <option>5000</option>
														    <option>7000</option>
														    <option selected>9000</option>
														    <option>Illimité</option>
													    </select>
													</div>
												</td>

												<td><?php echo $PRIX;?></td>

												<td><input type="submit" class="btn" style="background-color:#618b99 !important;  color:#FFF;" value="Valider" /></td>
											</form>
                        				</tr>

                        				<tr>
                        					<form action="send.php" method="post">
                        						<input type="hidden" name="name" value="dv-min" />
                        						<?php include("hidden.php");?>
	                        					<td><label for="dv-min">Temps estimé avant maintenance</label></td>

												<td>
													<div class="my-1 mr-sm-2">
													    <select class="custom-select my-1 mr-sm-2" id="dv-min" name="value">
														    <option>2 Semaines</option>
														    <option>2 Ans</option>
														    <option>10 Ans</option>
													    </select>
													</div>
												</td>

												<td><?php echo $DV_MIN;?></td>

												<td><input type="submit" class="btn" style="background-color:#618b99 !important; color:#FFF;" value="Valider" /></td>
											</form>
                        				</tr>

                        			</div>
                			</tbody>
        			</table>
	        		<form action="validation.php" method="post">
	        			<?php include("hidden.php");?>
	        			<input type="submit" class="btn btn-dark btn-lg btn-block" style="background-color:#254161 !important; margin-top:50px; color:#FFF;" value="Envoyer"/>
	        			<br/>
	        		</form>
    			</div>
			</div>	
		</div>
	</body>
</html>