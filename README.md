# Implementation Idea
## Inventory Management System
- Create a storage system for available items using a dynamically allocated array (in C). In C++, use a vector for convenience.
- The warehouse can store up to 100 items, each with the following data: 
  - Product name
  - Product code
  - Quantity
  - Price per item
  - A unique code for each product, automatically generated.

### System Features
#### Display Inventory (1)
- Use a MENU system to serve as the interface for the system:
  1. Display the items in stock (the system will notify you of items with low stock levels (< 20 units)).
  2. Automatically calculate the total value of goods in the warehouse.

#### Export Items (2)
1. Export items:
   - You will need to enter the product code and the quantity to export. The system will then prompt you to input export details for each item (product code, quantity).
2. If the requested export quantity exceeds the available stock, the system will display an error message and prompt you to re-enter the data.
3. After exporting, the warehouse information will be automatically updated for the user.

#### Import Items (3)
1. Choose whether to add a new product or restock an existing product.
2. For restocking, simply enter the product code, and the system will display the item's current information, allowing you to input the additional quantity.
3. For adding a new product, you will need to input all required details.

#### Sort Items (4)
This feature facilitates inventory checking:
1. Sort by price (ascending or descending).
2. Sort by quantity (ascending or descending).
   - Use a menu to select sorting order.

#### Search by Product Code (5)
1. When you enter a product code, the system will display the product's name, quantity, and price.
2. If the code is invalid, it will display a "Product not found" message.

#### View Inventory Change History (6)
1. All changes (imports, exports, or modifications) are logged in a file and can be viewed using this feature.

#### Delete an Item from Inventory (7)
1. Enter the product code of the item to be deleted, and it will be removed from the inventory.

#### Edit Product Price (8)
1. Enter the product code for the item you want to update and input the new price.

#### Exit the System (0)
   RETURN 0;
