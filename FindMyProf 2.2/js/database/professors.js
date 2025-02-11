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
name: 'Dr. Johan',
shortBio: 'Johan loves gosha.',
fullBio: 'Johan describes the topology of caracals.',
email: 'johan@mail.ca',
office: 'LEA 132',
officeHours: 'Never',
researchInterests: ['Cats'],
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
name: 'Dr. Calm',
shortBio: 'He\'s a chill guy.',
fullBio: 'Calm knows how to control his class.',
email: 'calm@mail.ca',
office: 'None',
officeHours: 'None',
researchInterests: ['Serenity','Orbital Mechanics'],
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