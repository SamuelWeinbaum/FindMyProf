document.addEventListener('DOMContentLoaded', () => {
    // Check if we're on a department page
    const profContainer = document.getElementById('professor-container');
    if (profContainer) {
        const department = document.body.getAttribute('data-department');
        loadDepartmentProfessors(department);
    }

    // Check if we're on a professor's page
    const profProfile = document.getElementById('professor-profile');
    if (profProfile) {
        const urlParams = new URLSearchParams(window.location.search);
        const profId = urlParams.get('id');
        if (profId) {
            loadProfessorProfile(profId);
        }
    }
});

function loadDepartmentProfessors(department) {
    const professors = getDepartmentProfessors(department);
    const container = document.getElementById('professor-container');
    
    container.innerHTML = '';

    professors.forEach(prof => {
        const profCard = document.createElement('div');
        profCard.classList.add('profile');
        profCard.classList.add(prof.acceptingStudents ? 'available' : 'unavailable');
        
        profCard.innerHTML = `
            <h3>${prof.name}</h3>
            <p>${prof.shortBio}</p>
            <p class="status">${prof.acceptingStudents ? 'Accepting Students' : 'Not Accepting Students'}</p>
            <div class="action-buttons">
                <a href="professor.html?id=${prof.id}" class="profile-link">View Full Profile</a>
                <button onclick="toggleBroadcastFromList('${prof.id}', this)" class="broadcast-button">
                    Add to Broadcast List
                </button>
            </div>
        `;
        
        container.appendChild(profCard);
    });
}

function loadProfessorProfile(profId) {
    const prof = getProfessorById(profId);
    if (!prof) return;

    document.title = prof.name;
    
    const profileSection = document.getElementById('professor-profile');
    profileSection.innerHTML = `
        <h2>${prof.name}</h2>
        <div class="profile-content">
            <h3>Research Interests</h3>
            <p>${prof.researchInterests.join(', ')}</p>
            
            <h3>Biography</h3>
            <p>${prof.fullBio}</p>
            
            <h3>Contact Information</h3>
            <p>Email: <a href="mailto:${prof.email}">${prof.email}</a></p>
            <p>Office: ${prof.office}</p>
            <p>Office Hours: ${prof.officeHours}</p>
            
            <div class="status-indicator ${prof.acceptingStudents ? 'available' : 'unavailable'}">
                ${prof.acceptingStudents ? 'Currently Accepting Students' : 'Not Accepting Students'}
            </div>
            
            <div class="action-buttons">
                <button onclick="contactProfessor('${prof.id}')">Contact</button>
                <button onclick="toggleBroadcastFromList('${prof.id}', this)" class="broadcast-button">
                    Add to Broadcast List
                </button>
            </div>
        </div>
    `;
}

function toggleBroadcastFromList(profId, button) {
    const isSelected = toggleBroadcastSelection(profId);
    updateBroadcastButton(button, isSelected);
}

function contactProfessor(profId) {
    const prof = getProfessorById(profId);
    alert(`Contact form for ${prof.name} would open here`);
}