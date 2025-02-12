// Professor data
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
            researchInterests: ['Number Theory', 'Cryptography', 'Algebraic Structures'],
            acceptingStudents: true
        },
        {
            id: 'math2',
            name: 'Dr. Michael Chen',
            shortBio: 'Expert in Mathematical Analysis and Topology',
            fullBio: 'Dr. Chen specializes in mathematical analysis and topology, with particular interest in manifold theory.',
            email: 'mchen@university.edu',
            office: 'Math Building 205',
            officeHours: 'Tuesday, Thursday 1-3pm',
            researchInterests: ['Mathematical Analysis', 'Topology', 'Differential Geometry'],
            acceptingStudents: true
        },
        {
            id: 'math3',
            name: 'Dr. Emily Martinez',
            shortBio: 'Focuses on Applied Mathematics and Modeling',
            fullBio: 'Dr. Martinez works on mathematical modeling of complex systems and numerical analysis.',
            email: 'emartinez@university.edu',
            office: 'Math Building 412',
            officeHours: 'Wednesday, Friday 10am-12pm',
            researchInterests: ['Applied Mathematics', 'Mathematical Modeling', 'Numerical Analysis'],
            acceptingStudents: false
        }
    ],
    physics: [
        {
            id: 'phys1',
            name: 'Dr. James Wilson',
            shortBio: 'Quantum Mechanics and Particle Physics Researcher',
            fullBio: 'Dr. Wilson has been conducting research in quantum mechanics and particle physics for over two decades.',
            email: 'jwilson@university.edu',
            office: 'Physics Building 201',
            officeHours: 'Monday, Wednesday 10am-12pm',
            researchInterests: ['Quantum Mechanics', 'Particle Physics', 'Quantum Field Theory'],
            acceptingStudents: true
        },
        {
            id: 'phys2',
            name: 'Dr. Lisa Park',
            shortBio: 'Specializes in Astrophysics and Cosmology',
            fullBio: 'Dr. Park studies the formation and evolution of galaxies, with a focus on dark matter distribution.',
            email: 'lpark@university.edu',
            office: 'Physics Building 305',
            officeHours: 'Tuesday, Thursday 3-5pm',
            researchInterests: ['Astrophysics', 'Cosmology', 'Dark Matter'],
            acceptingStudents: true
        },
        {
            id: 'phys3',
            name: 'Dr. Robert Brown',
            shortBio: 'Expert in Condensed Matter Physics',
            fullBio: 'Dr. Brown investigates quantum phenomena in materials and their potential applications in quantum computing.',
            email: 'rbrown@university.edu',
            office: 'Physics Building 410',
            officeHours: 'Monday, Friday 1-3pm',
            researchInterests: ['Condensed Matter Physics', 'Quantum Computing', 'Materials Science'],
            acceptingStudents: false
        }
    ]
};

// Helper functions
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