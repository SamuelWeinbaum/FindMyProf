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
},
{
id: 'math2',
name: 'Dr. Paul',
shortBio: 'He\'s on TV!',
fullBio: 'He is a very mean person.',
email: 'paul@paul.paul',
office: 'Paul\'s Office',
officeHours: 'Paul Studios',
researchInterests: ['Paul'],
acceptingStudents: false
}
],
physics: [
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
},
{
id: 'phys2',
name: 'Dr. Weinbaum',
shortBio: 'He looks a lot like GigaChad',
fullBio: 'He loves topoligcal manifolds and how they relate to general relativity.',
email: 'wb@edu.mail',
office: 'SUMS Lounge',
officeHours: 'Tuesdays 7am-9pm',
researchInterests: ['Topology','General Relativity','ODEs'],
acceptingStudents: true
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