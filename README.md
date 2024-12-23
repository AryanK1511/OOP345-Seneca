# Seneca College OOP345 Workshops and Labs
This repository contains all the OOP345 (Object Oriented Programming) workshops, milestones and labs that I have done as a student at Seneca College.

## Marks secured
- WS01 : 8.5 / 10 <br />
Having prototypes for the rule of 3 in the header would be good practice. Copy assignment operator doesn't deallocate memory prior to allocating new memory. It's not certain that the current obj doesn't already have memory prior (as it's an  previously existing object). Read function in part 2 should incorporate a std::string to allow for capturing a brand string of any length. Having a static char array as a buffer isn't a good fit. An alternative is a use of a reallocation loop though std::string is more straightforward.
- WS02 : 9 / 10 <br />
Functions added outside of the spec should be in the private scope (eg setEmpty). For the comparison of move vs copy it would better to do a direct comparison of the code to outline the exact differences between the two. Also it would be good to go more into how chrono works  and was used to measure the operations.
- WS03 : 9 / 10 <br />
Query function without const (display, size, operator[]). For the reasons to why templates aren't split, it's not just so it's easy to share via header includes but consider what occurs to the visibility of the template if split up. The full visibility of the templates definition needs to be available in the scope where it gets used. In a typical split this visibility breaks. The inclusion of the default constr to pair isn't listed in the reflection and the other functions reasonings should be written in aligned to why they were needed for the template to function.
- WS04 : 9.5 / 10 <br />
Copy assignment operator doesn't have a clause to validate the source object's resources before allocating memory in the case it's nullptr / set the current object's resource to nullptr if required.
- WS05 : 9.25 / 10
For the alternatives to the book/move duplication go into more depth of how it would be generally arranged/done. For example with the base class route, what would go in there and what was be in book/movie? Particular to this workshop the presence of the default constructor is necessary as there are objects make of movie/book that are default constructed. Where are these instances?
- WS06 : 8 / 10
m_dept is a public data member in Employee that supplies the value of m_department to Professor but there shouldn't be a notion of this in Employee and Professor should deal with the reading of that data from the file in its constructor. As the trim functionality is used multiple times and that there's a utils module it should be placed there to avoid and included to avoid repetition of code
- WS07 : 9.5 / 10
What is the reason as to why std::list can't be used with std::sort but rather use a member function?
- WS08 : 9.25 / 10
Reflection -7.5% reduction. Regarding the use of unique_ptr vs shared in the case of the workshop's singleton design, what other reasons are there that won't allow unique_ptr to be used here? Could it be make to be usable?
- Final Project : 86 / 100
  - MS1
    - Station constr should validate the param coming in before the extratction process (eg if it's empty)
    - There isn't the use of the more parameter from extractToken to validate whether this is more to read or not
  - MS2
    - CustOrder constr should validate its param
  - MS3
    - There are other situations where exceptions could/should be considered (eg if there are mulitple of the same station or multiple first stations).
    - A couple of range based for loops are used in the LM constr. Specs mention only one manual loop is permitted for reading the file.
   
### COURSE GRADE: 

# Disclaimer
Please don't just copy the code mindlessly without trying to solve the problems yourself, it's totally pointless if you actually wanna learn how to write software and a blatant violation of the [Academic Integrity](https://www.senecacollege.ca/about/policies/academic-integrity-policy.html) policy of the course.
