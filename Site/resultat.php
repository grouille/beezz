<?php
require("function.php");
$nombre_resultats = 4;
$tab = readValues();
$result = readResult($nombre_resultats);
if(isset($_POST['refresh']))
{
    $string = "";
    $fichier = fopen('solutions.txt', 'w');
    for($i=0; $i<$nombre_resultats; $i++)
    {
        $values = explode(";", $result[$i]);
        for($j=0; $j<count($values); $j++)
        {
            $var = $i.":".$j;
            $string = $string.$_POST[$var];
            if($j!=count($values)-1) $string = $string.";";
        }
        $string = $string."\n";
    }
    fputs($fichier, $string);
    fclose($fichier);
    $result = readResult($nombre_resultats);
}
else
{
    $fichier = fopen('solutions.txt', 'w');
    fclose($fichier);
}
$names = names($result, $tab);

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
                <div class="col-10 col-md-10 offset-md-1 offset-1">
                    <br/>
                    <form action="resultat.php" method="post">
                        <h1 style="margin-bottom:50px; margin-top:50px; border-bottom:1px solid #CCC; padding-bottom:20px;"><i class="fas fa-align-justify"></i> Résultats</h1>

                        <?php
                        for($i=0; $i<count($result); $i++)
                        {

                            ?>
                            <h2 style="margin-bottom:50px; margin-top:50px; border-bottom:1px solid #CCC; padding-bottom:20px;"><i class="fas fa-align-justify"></i> Solution <?php echo $i + 1;?></h2>
                            <table class="table table-striped table-bordered">
                                <tbody>
                                    <?php
                                    $j_max = intdiv(count($tab),4);
                                    $h_max = fmod(count($tab),4);
                                    for($j=0; $j<$j_max; $j++)
                                    {
                                    ?>
                                        <tr>
                                            <?php
                                            for($k=0; $k<4; $k++)
                                            {
                                                ?>
                                                <td>
                                                    <b><?php echo $names[$i][$j*($j_max-1)+$k][0];?></b>
                                                    <div class="form-group my-1 mr-sm-2">
                                                        <select class="custom-select my-1 mr-sm-2" id="selection" name="<?php echo $i.':'.($j*($j_max-1)+$k)?>">
                                                            <?php
                                                            $ind = -1;
                                                            foreach($tab[$j*($j_max-1)+$k]['option'] as $opt)
                                                            {
                                                                $ind = $ind + 1;
                                                                if($opt[0] == $names[$i][$j*($j_max-1)+$k][1])
                                                                {
                                                                    ?>
                                                                    <option value="<?php echo $ind;?>" selected><?php echo $opt[0];?></option>
                                                                    <?php
                                                                }
                                                                else
                                                                {
                                                                    ?>
                                                                    <option value="<?php echo $ind;?>"><?php echo $opt[0];?></option>
                                                                    <?php
                                                                }
                                                            }
                                                            ?>
                                                        </select>
                                                    </div>
                                                </td>
                                                <?php
                                            }
                                            ?>
                                        </tr>
                                    <?php
                                    }
                                    if($h_max != 0)
                                        {
                                            ?>
                                            <tr>
                                                <?php
                                                for($h=0; $h<$h_max; $h++)
                                                {
                                                    ?>
                                                    <td>
                                                        <b><?php echo $names[$i][4*$j_max+$h][0];?></b>
                                                        <div class="form-group my-1 mr-sm-2">
                                                            <select class="custom-select my-1 mr-sm-2" id="selection" name="<?php echo $i.':'.(4*($j_max-1)+$h)?>">
                                                                <?php
                                                                $ind = -1;
                                                                foreach($tab[4*($j_max-1)+$h]['option'] as $opt)
                                                                {
                                                                    $ind = $ind + 1;
                                                                    if($opt[0] == $names[$i][4*($j_max-1)+$h][1])
                                                                    {
                                                                        ?>
                                                                        <option value="<?php echo $ind;?>" selected><?php echo $opt[0];?></option>
                                                                        <?php
                                                                    }
                                                                    else
                                                                    {
                                                                        ?>
                                                                        <option value="<?php echo $ind;?>"><?php echo $opt[0];?></option>
                                                                        <?php
                                                                    }
                                                                }
                                                                ?>
                                                            </select>
                                                        </div>
                                                    </td>
                                                    <?php
                                                }
                                                ?>
                                            </tr>
                                            <?php
                                        }
                                    ?>
                                </tbody>
                            </table>
                            <table class="table table-striped table-bordered">
                                <tbody>
                                    <tr>
                                        <td style="width:25%;"><b>Score</b></td>
                                        <td><?php echo round(100*(moyenne($tab, 5, $result[$i])/total($tab, 5)+moyenne($tab, 6, $result[$i])/total($tab, 6)+moyenne($tab, 7, $result[$i])/total($tab, 7)+moyenne($tab, 8, $result[$i])/total($tab, 8)+moyenne($tab, 9, $result[$i])/total($tab, 9))/5);?>%</td>
                                    </tr>
                                    <tr>
                                        <td style="width:25%;"><b>Prix</b></td>
                                        <td><?php echo evaluer($result[$i], $tab);?>€</td>
                                    </tr>
                                    <tr>
                                        <td style="width:25%;"><b>Impact environnemental</b></td>
                                        <td><?php echo environnement($result[$i], $tab);?> </td>
                                    </tr>
                                    <tr>
                                        <td style="width:25%;"><b>Temps estimé avant maintenance</b></td>
                                        <td><?php echo life($result[$i], $tab);?></td>
                                    </tr>
                                    <tr>
                                        <td style="width:25%;"><b>Design</b></td>
                                        <td>
                                            <div class="progress">
                                                <div class="progress-bar progress-bar-striped" role="progressbar" style="background-color:#254161 !important; width: <?php echo round(100*moyenne($tab, 5, $result[$i])/total($tab, 5));?>%" aria-valuenow="<?php echo round(100*moyenne($tab, 6, $result[$i])/total($tab, 6));?>" aria-valuemin="0" aria-valuemax="100"></div>
                                            </div>
                                        </td>
                                    </tr>
                                    <tr>
                                        <td style="width:25%;"><b>Bien-Être</b></td>
                                        <td>
                                            <div class="progress">
                                                <div class="progress-bar progress-bar-striped" role="progressbar" style="background-color:#b7c8b7 !important; width: <?php echo round(100*moyenne($tab, 6, $result[$i])/total($tab, 6));?>%" aria-valuenow="<?php echo round(100*moyenne($tab, 6, $result[$i])/total($tab, 6));?>" aria-valuemin="0" aria-valuemax="100"></div>
                                            </div>
                                        </td>
                                    </tr>
                                    <tr>
                                        <td style="width:25%;"><b>Social & Solidaire</b></td>
                                        <td>
                                            <div class="progress">
                                                <div class="progress-bar progress-bar-striped" role="progressbar" style="background-color:#618b99 !important; width: <?php echo round(100*moyenne($tab, 7, $result[$i])/total($tab, 7));?>%" aria-valuenow="<?php echo round(100*moyenne($tab, 7, $result[$i])/total($tab, 7));?>" aria-valuemin="0" aria-valuemax="100"></div>
                                            </div>
                                        </td>
                                    </tr>
                                    <tr>
                                        <td style="width:25%;"><b>Engagement</b></td>
                                        <td>
                                            <div class="progress">
                                                <div class="progress-bar progress-bar-striped" role="progressbar" style="background-color:#d2be81 !important; width: <?php echo round(100*moyenne($tab, 8, $result[$i])/total($tab, 8));?>%" aria-valuenow="<?php echo round(100*moyenne($tab, 8, $result[$i])/total($tab, 8));?>" aria-valuemin="0" aria-valuemax="100"></div>
                                            </div>
                                        </td>
                                    </tr>
                                    <tr>
                                        <td style="width:25%;"><b>Productivité</b></td>
                                        <td>
                                            <div class="progress">
                                                <div class="progress-bar progress-bar-striped" role="progressbar" style="background-color:#cc816d !important; width: <?php echo round(100*moyenne($tab, 9, $result[$i])/total($tab, 9));?>%" aria-valuenow="<?php echo round(100*moyenne($tab, 9, $result[$i])/total($tab, 9));?>" aria-valuemin="0" aria-valuemax="100"></div>
                                            </div>
                                        </td>
                                    </tr>
                                </tbody>
                            </table>
                        <?php
                        }
                        ?>
                        <input type="hidden" name="refresh"  value=1 />
                        <input type="submit" class="btn btn-dark btn-lg btn-block" style="background-color:#254161 !important; margin-top:50px; color:#FFF;" value="Modifier"/>
                        <br/>
                    </form>
                </div>
            </div>  
        </div>
    </body>
</html>