<?php
	function makeFichier($design, $eco, $be, $soc, $eng, $prod, $prix, $dv, $capa)
	{
		$fichier = fopen('data.txt', 'w');
		if($dv == "2 Semaines") $dv = 0;
		else if($dv == "2 Ans") $dv = 1;
		else $dv = 2;
		$string = $design."\n".$eco."\n".$be."\n".$soc."\n".$eng."\n".$prod."\n".$prix."\n".$dv;//."\n".$capa;
		fputs($fichier, $string);
		fclose($fichier);
		header('Location: comming.php');
  		exit();
	}

	function readResult($nombre_resultats)
	{
		$fichier = fopen('solutions.txt', 'r');
		for($i=0; $i<$nombre_resultats; $i++)
		{
			$ligne = fgets($fichier);
			$tab[] = $ligne;
		}
		fclose($fichier);
		return $tab;
	}

	function names($solutions, $data) // renvoie les noms des options des solutions
	{
		$j = -1;
		foreach($solutions as $lign)
		{
			$values = explode(';', $lign);
			$i = -1;
			$j = $j + 1;
			foreach($values as $val)
			{
				$i = $i + 1;
				$tab[$j][$i][] = $data[$i]['nom'];
				$tab[$j][$i][] = $data[$i]['option'][intval($val)][0];
			}
		}
		return $tab;
	}

	function readValues()
	{
		$fichier = fopen('values.csv', 'r');
		$i = -1;
		$j = -1;
		while(($ligne = fgets($fichier)) !== false)
		{
			$val = explode(";", $ligne);
			if($val[0] == "P")
			{
				$i = $i + 1;
				$tab[$i]['nom'] = $val[1]; // nom du parametre
				$j = -1;
			}
			else
			{
				$j = $j + 1;
				$tab[$i]['option'][$j][] = $val[1]; // nom de l'option
				$tab[$i]['option'][$j][] = $val[2]; // prix
				$tab[$i]['option'][$j][] = $val[3]; // coefficient de multiplication du prix
				$tab[$i]['option'][$j][] = $val[4]; // duree de vie minimale (0, 1 ou 2) -> (2 Semaines, 2 Ans ou 10 Ans)
				$tab[$i]['option'][$j][] = $val[5]; // impact écologique
				$tab[$i]['option'][$j][] = $val[6]; // design
				$tab[$i]['option'][$j][] = $val[7]; // bien-être
				$tab[$i]['option'][$j][] = $val[8]; // social
				$tab[$i]['option'][$j][] = $val[9]; // engagement
				$tab[$i]['option'][$j][] = $val[10]; // productivite
			}
		}
		return $tab;
	}

	function environnement($solution, $data)
	{
		$values = explode(";", $solution);
		$impact = 0;
		$i = -1;
		foreach($values as $value)
		{
			$i = $i + 1;
			$impact = $impact + intval($data[$i]['option'][intval($value)][4]);
		}
		$env = $impact/($i+1);
		return round($env); 
	}

	function evaluer($solution, $data)
	{
		$values = explode(";", $solution);
		$prix = 0;
		$i = -1;
		foreach($values as $value)
		{
			$i = $i + 1;
			$prix = $prix + $data[$i]['option'][intval($value)][1];
		}
		$i = -1;
		foreach($values as $value)
		{
			$i = $i + 1;
			$prix = $prix*$data[$i]['option'][intval($value)][2];
		}
		return $prix;
	}

	function life($solution, $data)
	{
		$values = explode(";", $solution);
		$life = 2;
		$i = -1;
		foreach($values as $value)
		{
			$i = $i + 1;
			if(intval($data[$i]['option'][intval($value)][3]) < $life) $life = intval($data[$i]['option'][intval($value)][3]);
		}
		if($life == 2) {$res = "10 Ans";}
		elseif($life == 1) {$res = "2 Ans";}
		else {$res = "2 Semaines";}
		return $res; 
	}

	function total($data, $critere)
	{
		$i = -1;
		$total = 0;
		foreach($data as $d)
		{
			$i = $i + 1;
			$max = 0;
			foreach($d['option'] as $value)
				if(intval($value[$critere]) > $max) $max = intval($value[$critere]);
			$total = $total + $max;
		}
		return $total;
	}

	function moyenne($data, $critere, $solution)
	{
		$total = 0;
		$values = explode(";", $solution);
		for($i=0; $i<count($values); $i++)
		{
			$total = $total + intval($data[$i]['option'][intval($values[$i])][$critere]);
		}
		return $total;
	}
?>