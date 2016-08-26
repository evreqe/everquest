<link rel="stylesheet" type="text/css" href="index.css">

<!-- DataTables CSS -->
<link rel="stylesheet" type="text/css" href="//cdn.datatables.net/1.10.3/css/jquery.dataTables.css">

<!-- DataTables FixedHeader CSS -->
<link rel="stylesheet" type="text/css" href="//cdn.datatables.net/fixedheader/2.1.2/css/dataTables.fixedHeader.css">

<!-- DataTables ColVis CSS -->
<link rel="stylesheet" type="text/css" href="//cdn.datatables.net/colvis/1.1.1/css/dataTables.colVis.css">

<!-- jQuery -->
<script type="text/javascript" charset="utf8" src="//code.jquery.com/jquery-1.11.1.min.js"></script>
  
<!-- DataTables -->
<script type="text/javascript" charset="utf8" src="//cdn.datatables.net/1.10.3/js/jquery.dataTables.js"></script>

<!-- DataTables FixedHeader -->
<script type="text/javascript" charset="utf8" src="//cdn.datatables.net/fixedheader/2.1.2/js/dataTables.fixedHeader.min.js"></script>

<!-- DataTables ColVis -->
<script type="text/javascript" charset="utf8" src="//cdn.datatables.net/colvis/1.1.1/js/dataTables.colVis.min.js"></script>

<div id="top"></div>

<div id="main_div">

    <h3>Shards of Dalaya Vendor List</h3>

    <p>
        <a href="http://shardsofdalaya.com">Shards of Dalaya</a>
        |
        <a href="http://shardsofdalaya.com/vendorlist/">Vendor List</a>
        |
        <a href="http://wiki.shardsofdalaya.com">Wiki</a>
        |
        <a href="http://shardsofdalaya.com/fomelo/">Fomelo</a>
        |
        <a href="http://shardsofdalaya.com/forum/">Forum</a>
    </p>

    <div class="colvis_location"></div>

    <table id="vendor_list" class="display compact" cellspacing="0">
        <thead>
            <tr>
                <th>Name</th>
                <th>Item</th>
                <th>Icon</th>
                <th>Wiki</th>
                <th class="column_tags">Tags</th>
                <th>HP</th>
                <th>MANA</th>
                <th>AC</th>
                <th>DMG</th>
                <th>Atk Delay</th>
            </tr>
        </thead>

        <tfoot>
            <tr>
                <th>Name</th>
                <th>Item</th>
                <th>Icon</th>
                <th>Wiki</th>
                <th class="column_tags">Tags</th>
                <th>HP</th>
                <th>MANA</th>
                <th>AC</th>
                <th>DMG</th>
                <th>Atk Delay</th>
            </tr>
        </tfoot>
    </table>

    <p>
        <a href="http://shardsofdalaya.com">Shards of Dalaya</a>
        |
        <a href="http://shardsofdalaya.com/vendorlist/">Vendor List</a>
        |
        <a href="http://wiki.shardsofdalaya.com">Wiki</a>
        |
        <a href="http://shardsofdalaya.com/fomelo/">Fomelo</a>
        |
        <a href="http://shardsofdalaya.com/forum/">Forum</a>
    </p>

   <p><a href="#top">Top</a></p>

<div>

<script>
var getUrlParameter = function getUrlParameter(sParam)
{
    var sPageURL = decodeURIComponent(window.location.search.substring(1)),
        sURLVariables = sPageURL.split('&'),
        sParameterName,
        i;

    for (i = 0; i < sURLVariables.length; i++)
    {
        sParameterName = sURLVariables[i].split('=');

        if (sParameterName[0] === sParam)
        {
            return sParameterName[1] === undefined ? true : sParameterName[1];
        }
    }
};

$(document).ready
(
    function()
    {
        var dataFile = 'data/vendor_list.txt';

        var historyFile = getUrlParameter('history');

        if (historyFile != undefined)
        {
            dataFile = 'data/history/' + historyFile;
        }

        var table = $('#vendor_list').dataTable
        (
            {
                "ajax": dataFile,
                "iDisplayLength": 25,
                "columnDefs":
                [
                    {
                        "targets": 2,
                        "render": function (data, type, row, meta)
                        {
                            return '<img src="http://www.shardsofdalaya.com/fomelo/images/icons/item_' + data + '.png" class="item_icon"/>';
                        }
                    },
                    {
                        "targets": 3,
                        "render": function (data, type, row, meta)
                        {
                            return '<a href="' + data + '">View on Wiki</a>';
                        }
                    },
                    {
                        "targets": [4,5,6,7,8,9],
                        "visible": false
                    }
                ]
            }
        );

        new $.fn.dataTable.FixedHeader(table);

        var colvis = new $.fn.dataTable.ColVis(table);

        $(colvis.button()).insertAfter('div.colvis_location');
    }
);
</script>