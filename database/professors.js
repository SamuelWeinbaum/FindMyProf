const professors = {
math: [
{
id: 'math1',
name: 'Dr. Sarah Johnson',
shortBio: 'Specializes in Number Theory and Cryptography',
fullBio: 'Dr. Johnson has been teaching mathematics for over 15 years, with a focus on number theory and its applications in cryptography.',
email: 'sjohnson@university.edu',
office: 'Math Building 301',
officeHours: 'Monday, Wednesday 2-4pm',
researchInterests: ['Algebra','Number Theory'],
acceptingStudents: true
}
],
phys: [
{
id: 'phys1',
name: 'Dr. Lee',
shortBio: 'Dr. Lee loves physics!',
fullBio: 'Dr. Lee is a teacher first and a researcher second, making him an unconventional university professor.',
email: 'lee@uni.edu.ca',
office: 'RPHYS 201',
officeHours: 'Monday 1pm-3pm',
researchInterests: ['Quantum Mechanics'],
acceptingStudents: false
}
]
};


function getDepartmentProfessors(department) {
 		return professors[department] || [];
 }
 
 function getProfessorById(id) {
 	for (const dept in professors) {
 		const prof = professors[dept].find(p => p.id === id);
 		if (prof) return prof;
 	}
 	return null;
 } 