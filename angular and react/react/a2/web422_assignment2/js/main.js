



let saleData = [];
let page = 1;
const perPage = 10;


const saleTableTemplate = _.template(`

<% _.forEach(sales, function(sale){ %>

    <tr data-id = "<%- sale._id %>">
        
        <td><%- sale.customer.email %></td>
        <td><%- sale.storeLocation %></td>
        <td><%- (sale.items).length %></td>
        <td><%- moment.utc(sales.saleData).local().format('LLLL') %></td>
    </tr>
     <% }) %>
`);


const saleModelBodyTemplate = _.template(`



    <h4>Customer</h4>
    <strong>Email: <%- sale.customer.email %></strong> </br>
    <strong>Age: <%- sale.customer.age %></strong> </br>
    <strong>Satisfaction: <%- sale.customer.satisfaction %>/5</strong> </br>
    <br><br>
    <h4> Items: $ <%- sale.total.toFixed(2)%> </h4>
    <table class="table">
    <thead>
    <tr>
        <th>Product Name</th>
        <th>Quantity</th>
        <th>Price</th>
    </tr>
    </thead>

    <tbody>
    <% _.forEach(sale.items, function(itemFetch){ %>

        <tr> 
        
        <td> <%- itemFetch.name %> </td>        
        <td> <%- itemFetch.quantity %> </td>
        <td> <%- itemFetch.price %> </td>

        </tr>



   <% }); %>
    </tbody>
    </table>

 


`)

function loadSaleData() {

    fetch(`https://calm-island-34142.herokuapp.com/api/sales?page=${page}&perPage=${perPage}`)
        .then(response => response.json())
        .then(json => {

            saleData = json;

            $("#current-page").html(page);
            $("#current-page").attr("pageNo", page);
            
            const saleTable = saleTableTemplate({ sales: saleData });
            $("#sale-table tbody").html(saleTable);
            
            
        })
}


$(function () {

    loadSaleData();

    $("#sale-table tbody").on("click", "tr", function (e) {

        let clickedId = $(this).attr("data-id");


        let detailData = _.find(saleData, function (o) {
            return o._id == clickedId;
        });

        let clickedSale = detailData;
        let total = 0;
        for (let i = 0; i < clickedSale.items.length; i++) {
            total += clickedSale.items[i].quantity * clickedSale.items[i].price;
        }

        clickedSale.total = total;

        $(".modal-body").html(saleModelBodyTemplate({ 'sale': clickedSale }))
        $(".modal-title").html("sales: " + clickedSale._id);
        $("#sale-modal").modal({
            keyboard: false,
            backdrop: "static"
        })


    })

    $("#previous-page").on("click", function (e) {
        page = $("#current-page").attr("pageNo");
        if (page > 1) {
            page--;
            loadSaleData()
            $("#current-page").attr("pageNo", page);
            $("#current-page").html(page);

        } else {
            alert("This is first page");
        }
    });

    $("#next-page").on("click", function (e) {
        if (lastPage == false) {
            page = $("#current-page").attr("pageNo");
            page++;
            loadSaleData();
            $("#current-page").attr("pageNo", page);
            $("#current-page").html(page);
        }else{
            alert("This is last page");
        }
    });


});