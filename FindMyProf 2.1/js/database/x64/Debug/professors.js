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
name: 'Dr. Weinbaum',
shortBio: 'Yeah, I took GR in winter U1, no biggie.',
fullBio: 'Dr. Weinbaum is currently leading a project called FindMyProf, where students can find professors to do research with in a centralized website. Looking good so far!',
email: 'shmuly@yahoo.com',
office: 'SUMS Lounge',
officeHours: 'None',
researchInterests: ['General Relativity','Topology','Experimental Methods'],
acceptingStudents: false
},
{
id: 'phys3',
name: 'the',
shortBio: 'the',
fullBio: 'the',
email: 'the',
office: 'the',
officeHours: 'the',
researchInterests: ['the'],
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