# Using_Classes_for_products
This is code based on code that we wrote originally, but this time we are using classes to get the work done

1. Create a new project. You must name this Lab2_Task3.
2. Modify the code from Lab 1, Task 3 to use a class instead of a structure, the name must
3. be Product. The name is case-sensitive. Don’t initialize the values.
          a. Place the Class declaration into a separate .h file.
          b. Place the Class definition into a separate .cpp file.
          c. Add members for description (string), and taxExempt (bool).
4. Write the code to read the values for the items of the class from a text file. It should
prompt the user for the name of the file. We only want to read data from this file and do
not allow to modify its data. The text file should be human readable (the text file may
look like the following repeated as many times as necessary although you may decide on a different file format as long as it is human readable).
          ID: 914
          Units: 842
          Price: 12.95
          Description: Blue widget used for powering devices.
          TaxExempt: False
   
          ID: 915
          Units: 416
          Price: 14.95
          Description: Cordless Battery Push Mower.
          TaxExempt: True
6. Test Scenarios:
  • No Input File: If no input file is provided, output "Error: File not found.".
  • Empty File: If the input file is empty, output "Error: Empty file.". 
  • File with Fewer Items than Expected: If the input file contains fewer items than
    expected, the program processes all items. The expected number is 9.
  • File with More Items than Expected: If the input file contains more items than
    expected, the program processes only the defined number of items.
