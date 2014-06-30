// The variable 'choice' is of the type integer and contains
//   a choice the user made based on a numbered navigation menu

if (choice == 1) {
	cout << "Chose item 1";
} else if (choice == 2) {
	cout << "Chose item 2";
} else if (choice == 3) {
	cout << "Chose item 3";
} else if (choice == 4) {
	cout << "Chose item 4";
} else if (choice == -1) {
	cout << "You chose to exit the program";
	return 0;
} else {
	cout << "Invalid choice!";
}
