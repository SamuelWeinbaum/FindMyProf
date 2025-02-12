document.addEventListener('DOMContentLoaded', () => {
    // Get the current HTML filename
    const currentPage = window.location.pathname.split('/').pop();
    
    // Find the professor data that matches this page
    let currentProfessor = null;
    for (const dept in professorsData) {
        const professor = professorsData[dept].find(prof => prof.profileUrl === currentPage);
        if (professor) {
            currentProfessor = professor;
            break;
        }
    }

    // If we found matching professor data, update the page content
    if (currentProfessor) {
        document.querySelector('header h1').textContent = currentProfessor.name;
        document.title = currentProfessor.name;
        
        const section = document.querySelector('section');
        section.innerHTML = `
            <h2>Research Interests</h2>
            <p>${currentProfessor.researchInterests}</p>
            <h2>Biography</h2>
            <p>${currentProfessor.bio}</p>
            <h2>Contact Information</h2>
            <p>Email: ${currentProfessor.email}</p>
            <div class="action-buttons">
                <button class="contact-button" onclick="alert('Contact ${currentProfessor.name}')">Contact</button>
                <button class="broadcast-button" onclick="alert('Added ${currentProfessor.name} Add to emailing list')">Add to emailing list</button>
            </div>
        `;
    }
});