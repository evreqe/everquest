<link rel="stylesheet" type="text/css" href="index.css">

<!-- jQuery -->
<script type="text/javascript" charset="utf8" src="//code.jquery.com/jquery-1.11.1.min.js"></script>

<?php

$skillList = array
(
    '1H Blunt',
    '2H Blunt',
    '1H Slashing',
    '2H Slashing',
    'Piercing',
    '2H Piercing',
    'Hand to Hand',
    'Archery',
    'Throwing',
);

$spellSkillList = array
(
    'Abjuration',
    'Alteration',
    'Conjuration',
    'Divination',
    'Evocation',
);

$otherSkillList = array
(
    'Alcohol Tolerance',
    'Assassinate',
    'Backstab',
    'Bash',
    'Begging',
    'Bind Wound',
    'Block',
    'Channeling',
    'Disarm',
    'Dodge',
    'Double Attack',
    'Dragon Punch',
    'Dual Wield',
    'Eagle Strike',
    'Evade',
    'Flying Kick',
    'Hide',
    'Intimidation',
    'Kick',
    'Meditate',
    'Mend',
    'Offense',
    'Parry',
    'Pick Lock',
    'Pick Pocket',
    'Riposte',
    'Round Kick',
    'Safe Fall',
    'Sense Heading',
    'Sense Traps',
    'Slam',
    'Sneak',
    'Swimming',
    'Tail Rake',
    'Taunt',
    'Tiger Claw',
    'Tinkering',
    'Tracking',
);

$tradeskillList = array
(
    'Alchemy',
    'Baking',
    'Blacksmithing',
    'Brewing',
    'Fishing',
    'Fletching',
    'Jewelcrafting',
    'Make Poison',
    'Mining',
    'Pottery',
    'Tailoring',
);

$instrumentSkillList = array
(
    'All Instruments',
    'Wind Instruments',
    'Percussion Instruments',
    'Brass Instruments',
    'Stringed Instruments',
);

$elementalDamageList = array
(
    'Cold',
    'Fire',
    'Magic',
    'Disease',
    'Poison',
);

$effectFlagList = array
(
    'Worn',
    'Clicky',
    'Must Wear Clicky',
    'Combat',
    'Casting Time',
    'Melee Proc',
    'Bash Proc',
    'Kick Proc',
    'Reactive Proc',
);

$focusEffectList = array
(
    'Affliction Enhancement',
    'Bane Enhancement',
    'Casting Speed Increment',
    'Companion Health',
    'Companion Strength',
    'Control Enhancement',
    'Damage Increment',
    'Duration Increment',
    'Healing Increment',
    'Mana Conservation',
    'Range Increment',
    'Reagent Conservation',
);

$sourceList = array
(
    '[[Loot]]',
    'Merchant',
    'Quest',
    'Ground Spawn',
    'Starter',
    '[[Forage]]d',
    '[[Donator Items]]',
);

// TINY SMALL MEDIUM LARGE GIANT
$sizeList = array
(
    'Tiny',
    'Small',
    'Medium',
    'Large',
    'Giant',
);

// CHARM EAR HEAD FACE NECK SHOULDERS ARMS BACK WRIST RANGE HANDS PRIMARY SECONDARY FINGERS CHEST LEGS FEET WAIST
$slotList = array
(
    'slotCHARM'     => 'Charm',
    'slotEAR'       => 'Ear',
    'slotHEAD'      => 'Head',
    'slotFACE'      => 'Face',
    'slotNECK'      => 'Neck',
    'slotSHOULDERS' => 'Shoulders',
    'slotARMS'      => 'Arms',
    'slotBACK'      => 'Back',
    'slotWRIST'     => 'Wrist',
    'slotRANGE'     => 'Range',
    'slotHANDS'     => 'Hands',
    'slotPRIMARY'   => 'Primary',
    'slotSECONDARY' => 'Secondary',
    'slotFINGERS'   => 'Fingers',
    'slotCHEST'     => 'Chest',
    'slotLEGS'      => 'Legs',
    'slotFEET'      => 'Feet',
    'slotWAIST'     => 'Waist',
);

$slotResult = array
(
    'slotCHARM'     => '0',
    'slotEAR'       => '0',
    'slotHEAD'      => '0',
    'slotFACE'      => '0',
    'slotNECK'      => '0',
    'slotSHOULDERS' => '0',
    'slotARMS'      => '0',
    'slotBACK'      => '0',
    'slotWRIST'     => '0',
    'slotRANGE'     => '0',
    'slotHANDS'     => '0',
    'slotPRIMARY'   => '0',
    'slotSECONDARY' => '0',
    'slotFINGERS'   => '0',
    'slotCHEST'     => '0',
    'slotLEGS'      => '0',
    'slotFEET'      => '0',
    'slotWAIST'     => '0',
);

// WAR CLR PAL RNG SHD DRU MNK BRD ROG SHM NEC WIZ MAG ENC BST
$classList = array
(
    'classWAR' => 'Warrior',
    'classCLR' => 'Cleric',
    'classPAL' => 'Paladin',
    'classRNG' => 'Ranger',
    'classSHD' => 'Shadow Knight',
    'classDRU' => 'Druid',
    'classMNK' => 'Monk',
    'classBRD' => 'Bard',
    'classROG' => 'Rogue',
    'classSHM' => 'Shaman',
    'classNEC' => 'Necromancer',
    'classWIZ' => 'Wizard',
    'classMAG' => 'Magician',
    'classENC' => 'Enchanter',
    'classBST' => 'Beastlord',
);

$classResult = array
(
    'classWAR' => '0',
    'classCLR' => '0',
    'classPAL' => '0',
    'classRNG' => '0',
    'classSHD' => '0',
    'classDRU' => '0',
    'classMNK' => '0',
    'classBRD' => '0',
    'classROG' => '0',
    'classSHM' => '0',
    'classNEC' => '0',
    'classWIZ' => '0',
    'classMAG' => '0',
    'classENC' => '0',
    'classBST' => '0',
);

// HUM BAR ERU ELF HIE DEF HEF DWF TRL OGR HFL GNM IKS VAH FRG
$raceList = array
(
    'raceHUM' => 'Human',
    'raceBAR' => 'Barbarian',
    'raceERU' => 'Erudite',
    'raceELF' => 'Wood Elf',
    'raceHIE' => 'High Elf',
    'raceDEF' => 'Dark Elf',
    'raceHEF' => 'Half Elf',
    'raceDWF' => 'Dwarf',
    'raceTRL' => 'Troll',
    'raceOGR' => 'Ogre',
    'raceHFL' => 'Halfling',
    'raceGNM' => 'Gnome',
    'raceIKS' => 'Iksar',
    'raceVAH' => 'Vah Shir',
    'raceFRG' => 'Froglok',
);

$raceResult = array
(
    'raceHUM' => '0',
    'raceBAR' => '0',
    'raceERU' => '0',
    'raceELF' => '0',
    'raceHIE' => '0',
    'raceDEF' => '0',
    'raceHEF' => '0',
    'raceDWF' => '0',
    'raceTRL' => '0',
    'raceOGR' => '0',
    'raceHFL' => '0',
    'raceGNM' => '0',
    'raceIKS' => '0',
    'raceVAH' => '0',
    'raceFRG' => '0',
);

function getClassName($classABC)
{
    global $classList;

    foreach ($classList as $key => $val)
    {
        if ($key == $classABC)
        {
            return $val;
        }
    }

    return 'Unknown';
}

function getRaceName($raceABC)
{
    global $raceList;

    foreach ($raceList as $key => $val)
    {
        if ($key == $raceABC)
        {
            return $val;
        }
    }

    return 'Unknown';
}

function addPlusToStringNumber($number)
{
    if (intval($number) > 0)
    {
        if (strpos($number, '+') === false)
        {
            $number = '+' . $number;
        }
    }

    return $number;
}

if ($_SERVER['REQUEST_METHOD'] == 'POST')
{
    $name = $_POST['name'];

    $image = $_POST['image'];

    $source = $_POST['source'];

    $mob = $_POST['mob'];

    $flagmagic = $_POST['flagmagic'];

    if ($flagmagic == 'on' || $flagmagic == 'Yes')
    {
        $flagmagic = '1';
    }
    else
    {
        $flagmagic = '0';
    }

    $flaglore = $_POST['flaglore'];

    if ($flaglore == 'on' || $flaglore == 'Yes')
    {
        $flaglore = '1';
    }
    else
    {
        $flaglore = '0';
    }

    $flagnodrop = $_POST['flagnodrop'];

    if ($flagnodrop == 'on' || $flagnodrop == 'Yes')
    {
        $flagnodrop = '1';
    }
    else
    {
        $flagnodrop = '0';
    }

    $flagnorent = $_POST['flagnorent'];

    if ($flagnorent == 'on' || $flagnorent == 'Yes')
    {
        $flagnorent = '1';
    }
    else
    {
        $flagnorent = '0';
    }

    $flagboe = $_POST['flagboe'];

    if ($flagboe == 'on' || $flagboe == 'Yes')
    {
        $flagboe = '1';
    }
    else
    {
        $flagboe = '0';
    }

    $flagfac = $_POST['flagfac'];

    if ($flagfac == 'on' || $flagfac == 'Yes')
    {
        $flagfac = '1';
    }
    else
    {
        $flagfac = '0';
    }

    $flagaug = $_POST['flagaug'];

    if ($flagaug == 'on' || $flagaug == 'Yes')
    {
        $flagaug = '1';
    }
    else
    {
        $flagaug = '0';
    }

    $container = $_POST['container'];

    if ($container == 'on' || $container == 'Yes')
    {
        $container = '1';
    }
    else
    {
        $container = '0';
    }

    $skill = $_POST['skill'];

    $dmg      = $_POST['dmg'];
    $atkdelay = $_POST['atkdelay'];

    $ac = $_POST['ac'];

    $health = $_POST['health'];
    $mana   = $_POST['mana'];

    $str = $_POST['str'];
    $sta = $_POST['sta'];
    $agi = $_POST['agi'];
    $dex = $_POST['dex'];
    $wis = $_POST['wis'];
    $int = $_POST['int'];
    $cha = $_POST['cha'];

    $svfire    = $_POST['svfire'];
    $svcold    = $_POST['svcold'];
    $svmagic   = $_POST['svmagic'];
    $svdisease = $_POST['svdisease'];
    $svpoison  = $_POST['svpoison'];

    $aggression     = $_POST['aggression'];
    $critstrike     = $_POST['critstrike'];
    $dmgreduction   = $_POST['dmgreduction'];
    $flowingthought = $_POST['flowingthought'];
    $mindshield     = $_POST['mindshield'];
    $spellward      = $_POST['spellward'];
    $stunresist     = $_POST['stunresist'];

    $size = $_POST['size'];

    $wt = $_POST['wt'];

    if ($wt !== '')
    {
        if (strpos($wt, '.') === false)
        {
            $wt .= '.0';
        }
    }

    $cap     = $_POST['cap'];
    $sizecap = $_POST['sizecap'];
    $wtreduc = $_POST['wtreduc'];

    $reclvl = $_POST['reclvl'];
    $reqlvl = $_POST['reqlvl'];

    $augslot = $_POST['augslot'];

    $spdmgtype = $_POST['spdmgtype'];
    $spdmgnum  = $_POST['spdmgnum'];

    $focuseffect = $_POST['focuseffect'];

    $effect     = $_POST['effect'];
    $effectflag = $_POST['effectflag'];
    $effectcast = $_POST['effectcast'];

    $haste = $_POST['haste'];

    $tradeskilled = $_POST['tradeskilled'];

    $tradeskillsupply = $_POST['tradeskillsupply'];

    foreach ($classResult as $key => &$val)
    {
        $val = $_POST[$key];

        if ($val == 'on' || $val == 'Yes')
        {
            $val = '1';
        }
        else
        {
            $val = '0';
        }

        //echo $key . ' => ' . $val . '<br>';

        unset($val);
    }

    foreach ($raceResult as $key => &$val)
    {
        $val = $_POST[$key];

        if ($val == 'on' || $val == 'Yes')
        {
            $val = '1';
        }
        else
        {
            $val = '0';
        }

        //echo $key . ' => ' . $val . '<br>';

        unset($val);
    }

    foreach ($slotResult as $key => &$val)
    {
        $val = $_POST[$key];

        if ($val == 'on' || $val == 'Yes')
        {
            $val = '1';
        }
        else
        {
            $val = '0';
        }

        //echo $key . ' => ' . $val . '<br>';

        unset($val);
    }
}
?>

<div id="divmain">

<form id="formmain" method="post"> <!-- action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']);?>" -->

<table>

<tr>
<th>Name:</th>
<th>
<input type="text" name="name" value="<?php echo $name;?>">
</th>
</tr>

<tr>
<th>Image:</th>
<th>
<input type="number" min="0" step="1" name="image" value="<?php echo $image;?>">
<?php
if (isset($image) && $image)
{
    echo '<p>';
    echo '<img id="itemimage" src="http://www.shardsofdalaya.com/fomelo/images/icons/item_' . $image . '.png"/>';
    echo '</p>';
}
?>
</th>
</tr>

<tr>
<th>Source:</th>
<th>
<input type="text" name="source" list="datalistsources" placeholder="a,b,c,..." value="<?php echo $source;?>">
<datalist id="datalistsources">
<?php
foreach ($sourceList as $sourceName)
{
    echo '<option value="' . $sourceName . '">';
}
?>
<?php
foreach ($tradeskillList as $tradeskillName)
{
    echo '<option value="[[' . $tradeskillName . ']]">';
}
?>
</datalist>
</th>
</tr>

<tr>
<th>Mob:</th>
<th>
<input type="text" name="mob" placeholder="a,b,c,..." value="<?php echo $mob;?>">
<datalist id="datalistsources">
<?php
foreach ($sourceList as $sourceName)
{
    echo '<option value="' . $sourceName . '">';
}
?>
<?php
foreach ($tradeskillList as $tradeskillName)
{
    echo '<option value="[[' . $tradeskillName . ']]">';
}
?>
</datalist>
</th>
</tr>

<tr>
<th>Skill:</th>
<th>
<input type="text" name="skill" list="datalistskills" value="<?php echo $skill;?>">
<datalist id="datalistskills">
<?php
foreach ($skillList as $skillName)
{
    echo '<option value="' . $skillName . '">';
}
?>
</datalist>
</th>
</tr>

<tr>
<th>DMG:</th>
<th>
<input type="number" step="1" name="dmg" value="<?php echo $dmg;?>">
</th>
</tr>

<tr>
<th>Atk Delay:</th>
<th>
<input type="number" step="1" name="atkdelay" value="<?php echo $atkdelay;?>">
</th>
</tr>

<tr>
<th>AC:</th>
<th>
<input type="number" step="1" name="ac" value="<?php echo $ac;?>">
</th>
</tr>

<tr>
<th>HP:</th>
<th>
<input type="number" step="1" name="health" value="<?php echo $health;?>">
</th>
</tr>

<tr>
<th>MANA:</th>
<th>
<input type="number" step="1" name="mana" value="<?php echo $mana;?>">
</th>
</tr>

<tr>
<th>STR:</th>
<th>
<input type="number" step="1" name="str" value="<?php echo $str;?>">
</th>
</tr>

<tr>
<th>STA:</th>
<th>
<input type="number" step="1" name="sta" value="<?php echo $sta;?>">
</th>
</tr>

<tr>
<th>AGI:</th>
<th>
<input type="number" step="1" name="agi" value="<?php echo $agi;?>">
</th>
</tr>

<tr>
<th>DEX:</th>
<th>
<input type="number" step="1" name="dex" value="<?php echo $dex;?>">
</th>
</tr>

<tr>
<th>WIS:</th>
<th>
<input type="number" step="1" name="wis" value="<?php echo $wis;?>">
</th>
</tr>

<tr>
<th>INT:</th>
<th>
<input type="number" step="1" name="int" value="<?php echo $int;?>">
</th>
</tr>

<tr>
<th>CHA:</th>
<th>
<input type="number" step="1" name="cha" value="<?php echo $cha;?>">
</th>
</tr>

<tr>
<th>SV FIRE:</th>
<th>
<input type="number" step="1" name="svfire" value="<?php echo $svfire;?>">
</th>
</tr>

<tr>
<th>SV COLD:</th>
<th>
<input type="number" step="1" name="svcold" value="<?php echo $svcold;?>">
</th>
</tr>

<tr>
<th>SV MAGIC:</th>
<th>
<input type="number" step="1" name="svmagic" value="<?php echo $svmagic;?>">
</th>
</tr>

<tr>
<th>SV DISEASE:</th>
<th>
<input type="number" step="1" name="svdisease" value="<?php echo $svdisease;?>">
</th>
</tr>

<tr>
<th>SV POISON:</th>
<th>
<input type="number" step="1" name="svpoison" value="<?php echo $svpoison;?>">
</th>
</tr>

<tr>
<th>Aggression:</th>
<th>
<input type="number" step="1" name="aggression" value="<?php echo $aggression;?>"> %
</th>
</tr>

<tr>
<th>Critical Strike:</th>
<th>
<input type="number" step="1" name="critstrike" value="<?php echo $critstrike;?>"> %
</th>
</tr>

<tr>
<th>Damage Reduction:</th>
<th>
<input type="number" step="1" name="dmgreduction" value="<?php echo $dmgreduction;?>">
</th>
</tr>

<tr>
<th>Flowing Thought:</th>
<th>
<input type="number" step="1" name="flowingthought" value="<?php echo $flowingthought;?>">
</th>
</tr>

<tr>
<th>Mind Shield:</th>
<th>
<input type="number" step="1" name="mindshield" value="<?php echo $mindshield;?>"> %
</th>
</tr>

<tr>
<th>Spell Ward:</th>
<th>
<input type="number" step="1" name="spellward" value="<?php echo $spellward;?>"> %
</th>
</tr>

<tr>
<th>Stun Resist:</th>
<th>
<input type="number" step="1" name="stunresist" value="<?php echo $stunresist;?>"> %
</th>
</tr>

</table>

<table>

<tr>
<th>Size:</th>
<th>
<select name="size">
<?php
foreach ($sizeList as $sizeName)
{
    echo '<option value="' . $sizeName . '"';

    if (isset($size) && $size == $sizeName)
    {
        echo ' selected="selected"';
    }

    echo '>' . $sizeName . '</option>';
}
?>
</select>
</th>
</tr>

<tr>
<th>WT (Weight):</th>
<th>
<input type="number" min="0" step="0.1" name="wt" value="<?php echo $wt;?>">
</th>
</tr>

<tr id="trcap">
<th>Capacity:</th>
<th>
<input type="number" min="0" step="1" name="cap" value="<?php echo $cap;?>">
</th>
</tr>

<tr id="trsizecap">
<th>Size Capacity:</th>
<th>
<select name="sizecap">
<?php
foreach ($sizeList as $sizeName)
{
    echo '<option value="' . $sizeName . '"';

    if (isset($sizecap) && $sizecap == $sizeName)
    {
        echo ' selected="selected"';
    }

    echo '>' . $sizeName . '</option>';
}
?>
</select>
</th>
</tr>

<tr id="trwtreduc">
<th>Weight Reduction:</th>
<th>
<input type="number" min="0" max="100" step="1" name="wtreduc" value="<?php echo $wtreduc;?>"> %
</th>
</tr>

<tr>
<th>Recommended Level:</th>
<th>
<input type="number" min="1" max="65" step="1" name="reclvl" value="<?php echo $reclvl;?>">
</th>
</tr>

<tr>
<th>Required Level:</th>
<th>
<input type="number" min="1" max="65" step="1" name="reqlvl" value="<?php echo $reqlvl;?>">
</th>
</tr>

<tr>
<th>Augment Slot Types:</th>
<th>
<input type="text" name="augslot" placeholder="#,#,..." value="<?php echo $augslot;?>">
</th>
</tr>

<tr>
<th>Elemental Damage:</th>
<th>
<input type="text" name="spdmgtype" list="datalistelementaldamages" value="<?php echo $spdmgtype;?>">
<datalist id="datalistelementaldamages">
<?php
foreach ($elementalDamageList as $elementalDamageName)
{
    echo '<option value="' . $elementalDamageName . '">';
}
?>
</datalist>
</th>
</tr>

<tr>
<th>Elemental Damage #:</th>
<th>
<input type="number" step="1" name="spdmgnum" value="<?php echo $spdmgnum;?>">
</th>
</tr>

<tr>
<th>Focus Effect:</th>
<th>
<input type="text" name="focuseffect" list="datalistfocuseffects" value="<?php echo $focuseffect;?>">
<datalist id="datalistfocuseffects">
<?php
foreach ($focusEffectList as $focusEffectName)
{
    echo '<option value="' . $focusEffectName . '">';
}
?>
</datalist>
</th>
</tr>

<tr>
<th>Effect:</th>
<th>
<input type="text" name="effect" value="<?php echo $effect;?>">
</th>
</tr>

<tr>
<th>Effect Flag:</th>
<th>
<input type="text" name="effectflag" list="datalisteffectflags" value="<?php echo $effectflag;?>">
<datalist id="datalisteffectflags">
<?php
foreach ($effectFlagList as $effectFlagName)
{
    echo '<option value="' . $effectFlagName . '">';
}
?>
</datalist>
</th>
</tr>

<tr>
<th>Effect Cast:</th>
<th>
<input type="text" name="effectcast" value="<?php echo $effectcast;?>">
</th>
</tr>

<tr>
<th>Haste:</th>
<th>
<input type="number" min="0" max="100" step="1" name="haste" value="<?php echo $haste;?>"> %
</th>
</tr>

<tr>
<th>Tradeskilled:</th>
<th>
<input type="text" name="tradeskilled" list="datalisttradeskills" value="<?php echo $tradeskilled;?>">
<datalist id="datalisttradeskills">
<?php
foreach ($tradeskillList as $tradeskillName)
{
    echo '<option value="' . $tradeskillName . '">';
}
?>
</datalist>
</th>
</tr>

<tr>
<th>Tradeskill Supply:</th>
<th>
<input type="text" name="tradeskillsupply" list="datalisttradeskills" placeholder="a,b,c,..." value="<?php echo $tradeskillsupply;?>"> 
<datalist id="datalisttradeskills">
<?php
foreach ($tradeskillList as $tradeskillName)
{
    echo '<option value="' . $tradeskillName . '">';
}
?>
</datalist>
</th>
</tr>

</table>

<table>

<tr>
<th>Flags:</th>
<th>
<input type="checkbox" name="flagmagic"
<?php if (isset($flagmagic) && $flagmagic == '1') echo ' checked';?>
>Magic Item
<br>
<input type="checkbox" name="flaglore"
<?php if (isset($flaglore) && $flaglore == '1') echo ' checked';?>
>Lore Item
<br>
<input type="checkbox" name="flagnodrop"
<?php if (isset($flagnodrop) && $flagnodrop == '1') echo ' checked';?>
>No Drop
<br>
<input type="checkbox" name="flagnorent"
<?php if (isset($flagnorent) && $flagnorent == '1') echo ' checked';?>
>No Rent
<br>
<input type="checkbox" name="flagboe"
<?php if (isset($flagboe) && $flagboe == '1') echo ' checked';?>
>Bind on Equip
<br>
<input type="checkbox" name="flagfac"
<?php if (isset($flagfac) && $flagfac == '1') echo ' checked';?>
>Faction Bound
<br>
<input type="checkbox" name="flagaug"
<?php if (isset($flagaug) && $flagaug == '1') echo ' checked';?>
>Augmentation
</th>
</tr>

<tr>
<th>&nbsp</th>
</tr>

<tr>
<th>Misc:</th>
<th>
<input type="checkbox" name="container" id="checkboxcontainer"
<?php if (isset($container) && $container == '1') echo ' checked';?>
>Container
</th>
</tr>

<tr>
<th>&nbsp</th>
</tr>

<tr>
<th>Slots:</th>
<th>
<input type="button" id="buttonallslots" value="ALL">
<br>
<?php
foreach ($slotResult as $key => $val)
{
    //echo $key . '=>' . $val . '<br>';

    echo '<input type="checkbox" class="checkboxslot" name="' . $key . '"';

    if (isset($key) && $val == '1')
    {
        echo ' checked';
    }

    $slotName = substr($key, strlen('slot'));

    $slotName = ucfirst(strtolower($slotName));

    echo '>' . $slotName . '<br>';
}
?>
</th>
</tr>

</table>

<table>

<tr>
<th>Classes:</th>
<th>
<input type="button" id="buttonallclasses" value="ALL">
<br>
<?php
foreach ($classResult as $key => $val)
{
    //echo $key . '=>' . $val . '<br>';

    echo '<input type="checkbox" class="checkboxclass" name="' . $key . '"';

    if (isset($key) && $val == '1')
    {
        echo ' checked';
    }

    echo '>' . getClassName($key) . '<br>';
}
?>
</th>
</tr>

<tr>
<th>&nbsp</th>
</tr>

<tr>
<th>Races:</th>
<th>
<input type="button" id="buttonallraces" value="ALL">
<br>
<?php
foreach ($raceResult as $key => $val)
{
    //echo $key . '=>' . $val . '<br>';

    echo '<input type="checkbox" class="checkboxrace" name="' . $key . '"';

    if (isset($key) && $val == '1')
    {
        echo ' checked';
    }

    echo '>' . getRaceName($key) . '<br>';
}
?>
</th>
</tr>

</table>

<br>

<table>
<tr>
<th>

<p>
<input type="submit" class="formbutton" name="submit" value="Submit">
<br>
<br>
<br>
<br>
<input type="reset" class="formbutton" name="reset" value="Reset">
</p>

</th>
</tr>
</table>

</form>

<div id="divitemstats">

<textarea id="itemstats" spellcheck="false" rows="32" cols="48">
<?php
if ($source == '')
{
    echo '{{stub}}{{stub-source}}' . "\n";
}

echo '{{Itemstats' . "\n";

echo '| name = ' . $name;
echo "\n";

if ($image)
{
    echo '| image = ' . $image;
    echo "\n";
}

if ($source)
{
    $source = str_replace(', ', ',', $source);

    $source = trim($source, ',');

    $sourceValues = explode(',', $source);

    $sourceIndex = 1;

    foreach ($sourceValues as $sourceValue)
    {
        echo '| source' . $sourceIndex . ' = ' . $sourceValue;
        echo "\n";

        $sourceIndex++;
    }
}

if ($mob)
{
    $mob = str_replace(', ', ',', $mob);

    $mob = trim($mob, ',');

    $mobValues = explode(',', $mob);

    $mobIndex = 1;

    foreach ($mobValues as $mobValue)
    {
        echo '| mob' . $mobIndex . ' = ' . $mobValue;
        echo "\n";

        $mobIndex++;
    }
}

echo "<!--End Infobox - Below are stats-->";
echo "\n";

if (isset($flagmagic) && $flagmagic == '1')
{
    echo '| flagmagic = ' . $flagmagic;
    echo "\n";
}

if (isset($flaglore) && $flaglore == '1')
{
    echo '| flaglore = ' . $flaglore;
    echo "\n";
}

if (isset($flagnodrop) && $flagnodrop == '1')
{
    echo '| flagnodrop = ' . $flagnodrop;
    echo "\n";
}

if (isset($flagnorent) && $flagnorent == '1')
{
    echo '| flagnorent = ' . $flagnorent;
    echo "\n";
}

if (isset($flagboe) && $flagboe == '1')
{
    echo '| flagboe = ' . $flagboe;
    echo "\n";
}

if (isset($flagaug) && $flagaug == '1')
{
    echo '| flagaug = ' . $flagaug;
    echo "\n";
}

if (isset($container) && $container == '1')
{
    echo '| container = ' . $container;
    echo "\n";
}

if ($skill)
{
    echo '| skill = ' . $skill;
    echo "\n";
}

if ($dmg)
{
    echo '| dmg = ' . $dmg;
    echo "\n";
}

if ($atkdelay)
{
    echo '| atkdelay = ' . $atkdelay;
    echo "\n";
}

if ($ac)
{
    echo '| ac = ' . $ac;
    echo "\n";
}

if ($health)
{
    $health = addPlusToStringNumber($health);

    echo '| health = ' . $health;
    echo "\n";
}

if ($mana)
{
    $mana = addPlusToStringNumber($mana);

    echo '| mana = ' . $mana;
    echo "\n";
}

if ($str)
{
    $str = addPlusToStringNumber($str);

    echo '| str = ' . $str;
    echo "\n";
}

if ($sta)
{
    $sta = addPlusToStringNumber($sta);

    echo '| sta = ' . $sta;
    echo "\n";
}

if ($agi)
{
    $agi = addPlusToStringNumber($agi);

    echo '| agi = ' . $agi;
    echo "\n";
}

if ($dex)
{
    $dex = addPlusToStringNumber($dex);

    echo '| dex = ' . $dex;
    echo "\n";
}

if ($wis)
{
    $wis = addPlusToStringNumber($wis);

    echo '| wis = ' . $wis;
    echo "\n";
}

if ($int)
{
    $int = addPlusToStringNumber($int);

    echo '| int = ' . $int;
    echo "\n";
}

if ($cha)
{
    $cha = addPlusToStringNumber($cha);

    echo '| cha = ' . $cha;
    echo "\n";
}

if ($svfire)
{
    $svfire = addPlusToStringNumber($svfire);

    echo '| svfire = ' . $svfire;
    echo "\n";
}

if ($svcold)
{
    $svcold = addPlusToStringNumber($svcold);

    echo '| svcold = ' . $svcold;
    echo "\n";
}

if ($svmagic)
{
    $svmagic = addPlusToStringNumber($svmagic);

    echo '| svmagic = ' . $svmagic;
    echo "\n";
}

if ($svdisease)
{
    $svdisease = addPlusToStringNumber($svdisease);

    echo '| svdisease = ' . $svdisease;
    echo "\n";
}

if ($svpoison)
{
    $svpoison = addPlusToStringNumber($svpoison);

    echo '| svpoison = ' . $svpoison;
    echo "\n";
}

if ($aggression)
{
    $aggression = addPlusToStringNumber($aggression);

    echo '| aggression = ' . $aggression . '%';
    echo "\n";
}

if ($critstrike)
{
    $critstrike = addPlusToStringNumber($critstrike);

    echo '| critstrike = ' . $critstrike . '%';
    echo "\n";
}

if ($dmgreduction)
{
    $dmgreduction = addPlusToStringNumber($dmgreduction);

    echo '| dmgreduction = ' . $dmgreduction;
    echo "\n";
}

if ($flowingthought)
{
    $flowingthought = addPlusToStringNumber($flowingthought);

    echo '| flowingthought = ' . $flowingthought;
    echo "\n";
}

if ($mindshield)
{
    $mindshield = addPlusToStringNumber($mindshield);

    echo '| mindshield = ' . $mindshield . '%';
    echo "\n";
}

if ($spellward)
{
    $spellward = addPlusToStringNumber($spellward);

    echo '| spellward = ' . $spellward . '%';
    echo "\n";
}

if ($stunresist)
{
    $stunresist = addPlusToStringNumber($stunresist);

    echo '| stunresist = ' . $stunresist . '%';
    echo "\n";
}

if ($size)
{
    echo '| size = ' . $size;
    echo "\n";
}

if ($wt)
{
    echo '| wt = ' . $wt;
    echo "\n";
}

if (isset($container) && $container == '1')
{
    if ($cap)
    {
        echo '| cap = ' . $cap;
        echo "\n";
    }

    if ($sizecap)
    {
        echo '| sizecap = ' . $sizecap;
        echo "\n";
    }

    if ($wtreduc)
    {
        echo '| wtreduc = ' . $wtreduc . '%';
        echo "\n";
    }
}

if ($reclvl)
{
    echo '| reclvl = ' . $reclvl;
    echo "\n";
}

if ($reqlvl)
{
    echo '| reqlvl = ' . $reqlvl;
    echo "\n";
}

if ($augslot)
{
    $augslot = str_replace(' ','', $augslot);

    $augslot = trim($augslot, ',');

    $augslotValues = explode(',', $augslot);

    $augslotIndex = 1;

    foreach ($augslotValues as $augslotValue)
    {
        echo '| augslot' . $augslotIndex . ' = ' . $augslotValue;
        echo "\n";

        $augslotIndex++;
    }
}

if ($spdmgtype)
{
    echo '| spdmgtype = ' . $spdmgtype;
    echo "\n";

    if ($spdmgnum)
    {
        echo '| spdmgnum = ' . $spdmgnum;
        echo "\n";
    }
}

if ($focuseffect)
{
    echo '| focuseffect = ' . $focuseffect;
    echo "\n";
}

if ($effect)
{
    echo '| effect = ' . $effect;
    echo "\n";

    if ($effectflag)
    {
        echo '| effectflag = ' . $effectflag;
        echo "\n";
    }

    if ($effectcast)
    {
        echo '| effectcast = ' . $effectcast;
        echo "\n";
    }
}

if ($haste)
{
    echo '| haste = ' . $haste . '%';
    echo "\n";
}

if ($tradeskilled)
{
    echo '| tradeskilled = ' . $tradeskilled;
    echo "\n";
}

if ($tradeskillsupply)
{
    $tradeskillsupply = str_replace(', ', ',', $tradeskillsupply);

    $tradeskillsupply = trim($tradeskillsupply, ',');

    $tradeskillsupplyValues = explode(',', $tradeskillsupply);

    $tradeskillsupplyIndex = 1;

    foreach ($tradeskillsupplyValues as $tradeskillsupplyValue)
    {
        echo '| tradeskillsupply' . $tradeskillsupplyIndex . ' = ' . $tradeskillsupplyValue;
        echo "\n";

        $tradeskillsupplyIndex++;
    }
}

$slotIndex = 1;
foreach ($slotResult as $key => $val)
{
    if ($val == '1')
    {
        $slotName = substr($key, strlen('slot'));

        $slotName = ucfirst(strtolower($slotName));

        echo '| slot' . $slotIndex . ' = ' . $slotName;
        echo "\n";

        $slotIndex++;
    }
}

$classIndex = 1;
foreach ($classResult as $key => $val)
{
    if ($val == '1')
    {
        echo '| class' . $classIndex . ' = ' . substr($key, strlen('class'));
        echo "\n";

        $classIndex++;
    }
}

$raceIndex = 1;
foreach ($raceResult as $key => $val)
{
    if ($val == '1')
    {
        echo '| race' . $raceIndex . ' = ' . substr($key, strlen('race'));
        echo "\n";

        $raceIndex++;
    }
}

echo '}}';
?>
</textarea>

<p>
<input type="button" id="buttonselectall" value="Select All">
</p>

<p>
<a href="http://wiki.shardsofdalaya.com">Shards of Dalaya Wiki</a>
</p>

<p>
<a href="http://wiki.shardsofdalaya.com/index.php/Template:Itemstats">Itemstats Template</a>
</p>

<p>
<a href="http://wiki.shardsofdalaya.com/index.php/User:Rari/Item_Images">Item Images</a>
</p>

</div>

</div>

<script>
$( document ).ready
(
    function()
    {
        if ($('#checkboxcontainer').prop('checked') == false)
        {
            $('#trcap').css('display', 'none');
            $('#trsizecap').css('display', 'none');
            $('#trwtreduc').css('display', 'none');
        }
    }
);

$('#checkboxcontainer').click
(
    function()
    {
        $('#trcap').toggle();
        $('#trsizecap').toggle();
        $('#trwtreduc').toggle();
    }
);

$('#buttonselectall').click
(
    function()
    {
        $('#itemstats').select();
    }
);

$('#buttonallslots').click
(
    function()
    {
        var checkboxes = $('.checkboxslot');
        checkboxes.prop('checked', !checkboxes.prop('checked'));
    }
);

$('#buttonallclasses').click
(
    function()
    {
        var checkboxes = $('.checkboxclass');
        checkboxes.prop('checked', !checkboxes.prop('checked'));
    }
);

$('#buttonallraces').click
(
    function()
    {
        var checkboxes = $('.checkboxrace');
        checkboxes.prop('checked', !checkboxes.prop('checked'));
    }
);
</script>