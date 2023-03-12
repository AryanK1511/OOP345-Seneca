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
For the alternatives to the book/move duplication go into more depth of how it would be generally arranged/done. For example with the base class route, what would go in there and what was be in book/movie?
Particular to this workshop the presence of the default constructor is necessary as there are objects make of movie/book that are default constructed. Where are these instances?

# Disclaimer
Please don't just copy the code mindlessly without trying to solve the problems yourself, it's totally pointless if you actually wanna learn how to write software and a blatant violation of the [Academic Integrity](https://www.senecacollege.ca/about/policies/academic-integrity-policy.html) policy of the course.
